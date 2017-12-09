<<<<<<< HEAD
//
// Created by 정수민 on 2017. 12. 9..
//

#include "map.h"
#include "block.h"
#include <iostream>
//#include <random>
=======
#include "map.h"
#include "block.h"
#include <iostream>
#include <random>
>>>>>>> a06a74c11b85565082ab833b08e6a146c9982b3e

using namespace std;

Map::Map(int s) {
<<<<<<< HEAD
    this->size = s;
    map = new Block*[s];
    for (int i = 0; i<s; i++)
        map[i] = new Block[s];
}

Map::~Map() {
    delete[] map;
    map = NULL;
=======
	this->size = s;
	map = new Block*[s];
	for (int i = 0; i<s; i++)
		map[i] = new Block[s];

}

Map::~Map() {
	delete[] map;
	map = NULL;
>>>>>>> a06a74c11b85565082ab833b08e6a146c9982b3e
}

void Map::operator+(Block b)
{
<<<<<<< HEAD
    /*
    random_device rd;
    mt19937_64 rng(rd());
    uniform_int_distribution<__int_64> dist(1, size*size); // random variable 만들기 위한 코드
    // "__int_64" <-- "__int64"
     */

    int ranNum = rand() % (size*size) +1;
    int i,j;

    for(i=0; i<size; i++)
    {
        for(j=0;j<size;j++)
        {
            if(map[i][j].getNum() == 0)
                ranNum--;

            if(ranNum == 0)
                map[i][j].setNum(b.getNum());
        }
    }
=======
	random_device rd;
	mt19937_64 rng(rd());
	uniform_int_distribution<__int64> dist(1, size*size); // random variable 만들기 위한 코드 

	int rand = dist(rng);
	int i,j;

	for(i=0; i<size; i++)
	{
		for(j=0;j<size;j++)
		{
			if(map[i][j].num == 0)
			rand--;

			if(rand == 0)
			map[i][j].num = b.num;
		}
	}
>>>>>>> a06a74c11b85565082ab833b08e6a146c9982b3e
}

bool Map::check()
{
<<<<<<< HEAD
    int i, j;
    int center;
    int temp;

    for (i = 0; i<size; i++)
    {
        for (j = 0; j<size; j++)
        {
            if (i % 2 != j % 2)
                continue;
            center = map[i][j].getNum();

            if (i - 1 >= 0) {
                temp = map[i - 1][j].getNum();
                if (center == temp)
                    return true;
            }

            if (j - 1 >= 0) {
                temp = map[i][j - 1].getNum();
                if (center == temp)
                    return true;
            }

            if (j + 1<size) {
                temp = map[i][j + 1].getNum();
                if (center == temp)
                    return true;
            }

            if (i + 1<size) {
                temp = map[i][j + 1].getNum();
                if (center == temp)
                    return true;
            }
        }
    }
    return false;
=======
	int i, j;
	int center;
	int temp;

	for (i = 0; i<size; i++)
	{
		for (j = 0; j<size; j++)
		{
			if (i % 2 != j % 2)
				continue;
			center = map[i][j].num;

			if (i - 1 >= 0) {
				temp = map[i - 1][j].num;
				if (center == temp)
					return true;
			}

			if (j - 1 >= 0) {
				temp = map[i][j - 1].num;
				if (center == temp)
					return true;
			}

			if (j + 1<size) {
				temp = map[i][j + 1].num;
				if (center == temp)
					return true;
			}

			if (i + 1<size) {
				temp = map[i][j + 1].num;
				if (center == temp)
					return true;
			}
		}
	}
	return false;
>>>>>>> a06a74c11b85565082ab833b08e6a146c9982b3e
}

void Map::move(char input)
{
<<<<<<< HEAD
    if (input == 'u')
    {
        for (int j = 0; j<size; j++)
        {
            int* arr = new int[size];
            int i;

            for (i = 0; i<size; i++)
                arr[i] = (map[i][j].getNum() == 0) ? 0 : 1;

            for (i = 0; i<size; i++)
            {
                if (arr[i] == 1)
                {
                    int num1 = map[i][j].getNum();
                    for (int k = i + 1; k<size; k++)
                    {
                        if (arr[k] == 1)
                        {
                            int num2 = map[k][j].getNum();
                            if (num1 == num2)
                            {
                                map[i][j].setNum(num1 + num2);
                                map[k][j].setNum(0);
                                arr[k] = 0;
                                //score.s_add(num1+num2);
                                break;
                            }
                        }
                    }
                }
            }

            int index = 0;
            for (i = 0; i<size; i++)
            {
                if (arr[i] == 1)
                {
                    if (index != i)
                    {
                        map[index][j] = map[i][j];
                        map[i][j].setNum(0);
                        map[i][j].setBonus(0);
                        arr[i] = 0;
                        index++;
                    }
                }
            }
        }
    }

    else if (input == 'd')
    {
        for (int j = 0; j<size; j++)
        {
            int* arr = new int[size];
            int i;

            for (i = 0; i<size; i++)
                arr[i] = (map[i][j].getNum() == 0) ? 0 : 1;

            for (i = size - 1; i >= 0; i--)
            {
                if (arr[i] == 1)
                {
                    int num1 = map[i][j].getNum();
                    for (int k = i - 1; k >= 0; k--)
                    {
                        if (arr[k] == 1)
                        {
                            int num2 = map[k][j].getNum();
                            if (num1 == num2)
                            {
                                map[i][j].setNum(num1 + num2);
                                map[k][j].setNum(0);
                                arr[k] = 0;
                                //score.s_add(num1+num2);
                                break;
                            }
                        }
                    }
                }
            }
            int index = size - 1;
            for (i = size - 1; i >= 0; i--)
            {
                if (arr[i] == 1)
                {
                    if (index != i)
                    {
                        map[index][j] = map[i][j];
                        map[i][j].setNum(0);
                        map[i][j].setBonus(0);
                        arr[i] = 0;
                        index--;
                    }
                }
            }
        }
    }

    else if (input == 'l')
    {
        for (int i = 0; i<size; i++)
        {
            int* arr = new int[size];
            int j;

            for (j = 0; j<size; j++)
                arr[j] = (map[i][j].getNum() == 0) ? 0 : 1;

            for (j = 0; j<size; j++)
            {
                if (arr[j] == 1)
                {
                    int num1 = map[i][j].getNum();
                    for (int k = j + 1; k<size; k++)
                    {
                        if (arr[k] == 1)
                        {
                            int num2 = map[i][k].getNum();
                            if (num1 == num2)
                            {
                                map[i][j].setNum(num1 + num2);
                                map[i][k].setNum(0);
                                arr[k] = 0;
                                //score.s_add(num1+num2);
                                break;
                            }
                        }
                    }
                }
            }
            int index = 0;
            for (j = 0; j<size; j++)
            {
                if (arr[j] == 1)
                {
                    if (index != i)
                    {
                        map[i][index] = map[i][j];
                        map[i][j].setNum(0);
                        map[i][j].setBonus(0);
                        arr[j] = 0;
                        index++;
                    }
                }
            }
        }
    }

    else if (input == 'r')
    {
        for (int i = 0; i<size; i++)
        {
            int* arr = new int[size];
            int j;

            for (j = size - 1; j >= 0; j--)
                arr[j] = (map[i][j].getNum() == 0) ? 0 : 1;

            for (j = size - 1; j >= 0; j--)
            {
                if (arr[j] == 1)
                {
                    int num1 = map[i][j].getNum();
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (arr[k] == 1)
                        {
                            int num2 = map[i][k].getNum();
                            if (num1 == num2)
                            {
                                map[i][j].setNum(num1 + num2);
                                map[i][k].setNum(0);
                                arr[k] = 0;
                                //score.s_add(num1+num2);
                                break;
                            }
                        }
                    }
                }
            }
            int index = size - 1;
            for (j = size - 1; j >= 0; j--)
            {
                if (arr[j] == 1)
                {
                    if (index != i)
                    {
                        map[i][index] = map[i][j];
                        map[i][j].setNum(0);
                        map[i][j].setBonus(0);
                        arr[j] = 0;
                        index--;
                    }
                }
            }
        }
    }

    else
    {
        //방향키 입력 다시하도록 시키기..?
    }
=======
	if (input == 'u')
	{
		for (int j = 0; j<size; j++)
		{
			int* arr = new int[size];
			int i;

			for (i = 0; i<size; i++)
				arr[i] = (map[i][j].num == 0) ? 0 : 1;

			for (i = 0; i<size; i++)
			{
				if (arr[i] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = i + 1; k<size; k++)
					{
						if (arr[k] == 1)
						{
							int num2 = map[k][j].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[k][j].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}

			int index = 0;
			for (i = 0; i<size; i++)
			{
				if (arr[i] == 1)
				{
					if (index != i)
					{
						map[index][j] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[i] = 0;
						index++;
					}
				}
			}
		}
	}

	else if (input == 'd')
	{
		for (int j = 0; j<size; j++)
		{
			int* arr = new int[size];
			int i;

			for (i = 0; i<size; i++)
				arr[i] = (map[i][j].num == 0) ? 0 : 1;

			for (i = size - 1; i >= 0; i--)
			{
				if (arr[i] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = i - 1; k >= 0; k--)
					{
						if (arr[k] == 1)
						{
							int num2 = map[k][j].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[k][j].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}
			int index = size - 1;
			for (i = size - 1; i >= 0; i--)
			{
				if (arr[i] == 1)
				{
					if (index != i)
					{
						map[index][j] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[i] = 0;
						index--;
					}
				}
			}
		}
	}

	else if (input == 'l')
	{
		for (int i = 0; i<size; i++)
		{
			int* arr = new int[size];
			int j;

			for (j = 0; j<size; j++)
				arr[j] = (map[i][j].num == 0) ? 0 : 1;

			for (j = 0; j<size; j++)
			{
				if (arr[j] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = j + 1; k<size; k++)
					{
						if (arr[k] == 1)
						{
							int num2 = map[i][k].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[i][k].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}
			int index = 0;
			for (j = 0; j<size; j++)
			{
				if (arr[j] == 1)
				{
					if (index != i)
					{
						map[i][index] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[j] = 0;
						index++;
					}
				}
			}
		}
	}

	else if (input == 'r')
	{
		for (int i = 0; i<size; i++)
		{
			int* arr = new int[size];
			int j;

			for (j = size - 1; j >= 0; j--)
				arr[j] = (map[i][j].num == 0) ? 0 : 1;

			for (j = size - 1; j >= 0; j--)
			{
				if (arr[j] == 1)
				{
					int num1 = map[i][j].num;
					for (int k = j - 1; k >= 0; k--)
					{
						if (arr[k] == 1)
						{
							int num2 = map[i][k].num;
							if (num1 == num2)
							{
								map[i][j].num = num1 + num2;
								map[i][k].num = 0;
								arr[k] = 0;
								//score.s_add(num1+num2);
								break;
							}
						}
					}
				}
			}
			int index = size - 1;
			for (j = size - 1; j >= 0; j--)
			{
				if (arr[j] == 1)
				{
					if (index != i)
					{
						map[i][index] = map[i][j];
						map[i][j].num = 0;
						map[i][j].bonus = 0;
						arr[j] = 0;
						index--;
					}
				}
			}
		}
	}

	else
	{
		//방향키 입력 다시하도록 시키기..? 
	}
>>>>>>> a06a74c11b85565082ab833b08e6a146c9982b3e
}