#include <iostream>
#include "block.h"
using namespace std;

#include "map.h"

using namespace std;

int main()
{
	Map m(4);
	cout << m.map[1][1].getCol() << endl;

	int in;
	cin >> in;

	return 0;
}
