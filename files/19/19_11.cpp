#include <iostream>
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
	for (int i = 0; i < 5; ++i)
		DoPrint(i);
	cout << endl;

	return 0;
}
////
//0 1 2 3 4

