#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class Print
{
public:
	void operator()(const T &t)
	{
		cout << t << " ";
	}
};

int main()
{
	Print<int> DoPrint;
	vector<int> vInt(5);
	for (int i = 0; i < 5; ++i)
		vInt[i] = i * 3;

	cout << "for_each()\n";
	for_each(vInt.begin(), vInt.end(), DoPrint);
	cout << "\n";

	return 0;
}
////
//for_each()
//0 3 6 9 12

