#include <iostream>
#include <list>
using namespace std;

typedef list<int> IntegerList;

int main()
{
	IntegerList intList;
	for (int i = 1; i <= 10; ++i)
		intList.push_back(i * 2);

	for (IntegerList::const_iterator ci = intList.begin(); ci != intList.end(); ++ci)
		cout << *ci << " ";
	cout << endl;

	return 0;
}
////
2 4 6 8 10 12 14 16 18 20

