#include <iostream>

const int DefaultSize = 10;

template <class T>	// оголошуємо шаблон і параметр
class Array		// параметризований класс
{
public:
	// конструктори
	Array(int itsSize = DefaultSize);
	Array(const Array &rhs);
	~Array() { delete[] pType; }
	// оператори
	Array &operator=(const Array &);
	T &operator[](int offSet) { return pType[offSet]; }
	// методи доступу
	int getSize() { return itsSize; }

private:
	T *pType;
	int itsSize;
};
