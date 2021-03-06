#include "map.h"
#include <stdlib.h>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

Map::Map() {
	map = new Block*[9];
	for (int i = 0; i<9; i++)
		map[i] = new Block[9];
}

Map::~Map() {
	for (int i = 0; i < size; i++)
		delete[] this->map[i];
    delete[] map;
}

void Map::setSize(int s) {
	this -> size = s;
}

int Map::getSize() {
	return size;
}

int Map::getScore(){
	return score;
}

int Map::countEmpty(){
	int count = 0;
	for (int i=0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j].getNum() == -1)
				count++;
		}
	}
	return count;
}

int make_random(int max) {
	int secretNumber = 0;
	srand(unsigned(time(0)));
	secretNumber = ( rand() % max )+1;
	return secretNumber;
}

void Map::operator+() {
	int temp = (make_random(2) % 2 == 0) ? 2 : 4;
	operator+(temp);
}

void Map::operator+(int num){
	int ranNum = make_random(countEmpty());
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (map[i][j].getNum() == -1)
				ranNum--;

			if (ranNum == 0){
				map[i][j].setNum(num);
				if (b_count == 10){
					map[i][j].setBonus(true);
					b_count = 0;
				}
				else 
					b_count++;
				return;
			}
		}
	}
}

int Map::check()
{
	int arr[2] = { 0, };

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i % 2 != j % 2)
				continue;
			int center = map[i][j].getNum();
			if (center == -1)
				continue;

			if (i - 1 >= 0 && center == map[i - 1][j].getNum())
				arr[0] = 1;

			if (j - 1 >= 0 && center == map[i][j - 1].getNum())
				arr[1] = 1;

			if (j + 1 < size && center == map[i][j + 1].getNum())
				arr[1] = 1;

			if (i + 1 < size && center == map[i + 1][j].getNum())
				arr[0] = 1;
		}
	}

	if (arr[0] == 1 && arr[1] == 1)
		return 4;
	else if (arr[0] == 1 && arr[1] == 0)
		return 3;
	else if (arr[0] == 0 && arr[1] == 1)
		return 2;
	else
		return 0;
}

void Map::move(char input)
{
	int check_m = 0;
	if (input == 'u' || input == 'd') {
		bool btemp = (input == 'u') ? true : false;

		for (int j = 0; j < size; j++) {
			int *arr = new int[size];

			for (int i = 0; i < size; i++)
				arr[i] = (map[i][j].getNum() == -1) ? 0 : 1;
			
			int index = btemp ? 0 : size - 1;
			int cnt = btemp ? +1 : -1;
			
			for (int m = 0; m < size; m++) {
				int i = btemp ? m : size - m - 1;
				
				if (arr[i] == 1) {
					int num1 = map[i][j].getNum();
					int k = btemp ? i + 1 : i - 1;

					while (k < size && k >= 0) {
						if (arr[k] == 1) {
							int num2 = map[k][j].getNum();
							if (num1 == num2) {
								addScore(map[i][j], map[k][j]);
								map[i][j].setNum(num1 + num2);
								map[k][j].setNum(-1);
								arr[k] = 0;
								check_m++;
								break;
							}
							else break;
						}
						k += cnt;
					}
				}
			}
			
			for (int m = 0; m < size; m++) {
				int i = btemp ? m : size - m - 1;
				if (arr[i] == 1) {
					if (index != i) {
						map[index][j].setNum(map[i][j].getNum());
						map[index][j].setBonus(map[i][j].getBonus());
						map[i][j].setNum(-1);
						map[i][j].setBonus(0);
						arr[i] = 0;
						check_m++;
					}
					index += cnt;
				}
			}
			delete[] arr;
		}
	}
	else if (input == 'l' || input == 'r') {
		bool btemp = (input == 'l') ? true : false;

		for (int i = 0; i < size; i++) {
			int *arr = new int[size];

			for (int j = 0; j < size; j++)
				arr[j] = (map[i][j].getNum() == -1) ? 0 : 1;
				
			int index = btemp ? 0 : size - 1;
			int cnt = btemp ? +1 : -1;

			for (int m = 0; m < size; m++) {
				int j = btemp ? m : size - m - 1;
				if (arr[j] == 1) {
					int num1 = map[i][j].getNum();
					int k = btemp ? j + 1 : j - 1;

					while (k < size && k >= 0) {
						if (arr[k] == 1) {
							int num2 = map[i][k].getNum();
							if (num1 == num2) {
								addScore(map[i][j], map[i][k]);
								map[i][j].setNum(num1 + num2);
								map[i][k].setNum(-1);
								arr[k] = 0;
								check_m++;
								break;
							}
							else break;
						}
						k += cnt;
					}
				}
			}
			for (int m = 0; m < size; m++) {
				int j = btemp ? m : size - m - 1;
				if (arr[j] == 1) {
					if (index != j) {
						map[i][index].setNum(map[i][j].getNum());
						map[i][index].setBonus(map[i][j].getBonus());
						map[i][j].setNum(-1);
						map[i][j].setBonus(0);
						arr[j] = 0;
						check_m++;
					}
					index += cnt;
				}
			}
			delete[] arr;
		}
	}
	if (check_m == 0)
		throw 1;
}
