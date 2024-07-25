#include <iostream>
using namespace std;

const int DefaultSize = 10;

// звичайний клас Animal для
// створення для масиву тварин

class Animal
{
public:
	Animal(int);
	Animal();
	~Animal() {}
	int Getweight() const { return itsWeight; }
	void Display() const { cout << itsWeight; }

private:
	int itsWeight;
};

Animal::Animal(int weight) : itsWeight(weight)
{
}

Animal::Animal() : itsWeight(0)
{
}

template <class T> // оголошуємо шаблон і параметр
class Array		   // параметризований класс
{
public:
	// конструктори
	Array(int itsSize = DefaultSize);
	Array(const Array &rhs);
	~Array() { delete[] pType; }
	// оператори
	Array &operator=(const Array &);
	T &operator[](int offSet) { return pType[offSet]; }
	const T &operator[](int offSet) const { return pType[offSet]; }
	// методи доступу
	int GetSize() const { return itsSize; }
	// функція-друг
	template <typename U> // усі екземпляри цього шаблону є моїми друзями
	friend ostream &operator<<(ostream &, const Array<T> &);

private:
	T *pType;
	int itsSize;
};

template <typename T>
ostream &operator<<(ostream &output, const Array<T> &theArray)
{
	for (int i = 0; i < theArray.GetSize(); i++)
		output << "[" << i << "] " << theArray[i] << endl;
	return output;
}

// виконання...

// виконуємо кнструктор
template <class T>
Array<T>::Array(int size) : itsSize(size)
{
	pType = new T[size];
	for (int i = 0; i < size; i++)
		pType[i] = 0;
}

// конструктор-копіювальник
template <class T>
Array<T>::Array(const Array &rhs)
{
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for (int i = 0; i < itsSize; i++)
		pType[i] = rhs[i];
}

// оператор присвлювання
template <class T>
Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
		return *this;
	delete[] pType;
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for (int i = 0; i < itsSize; i++)
		pType[i] = rhs[i];
	return this;
}

// виконуюча програиа
int main()
{
	bool Stop = false; // признак для циклу
	int offset, value;
	Array<int> theArray;

	while (!Stop)
	{
		cout << "Enter an offset (0-9) ";
		cout << "and a value. (-1 to stop): ";
		cin >> offset >> value;

		if (offset < 0)
			break;

		if (offset > 9)
		{
			cout << "****Please use values between 0 and 9. ***\n";
			continue;
		}

		theArray[offset] = value;
	}
	cout << "\nHere's the entire array:\n";
	cout << theArray << endl;
	return 0;
}
////
Enter an offset (0-9) and a value. (-1 to stop): 1 10
Enter an offset (0-9) and a value. (-1 to stop): 2 20
Enter an offset (0-9) and a value. (-1 to stop): 3 30
Enter an offset (0-9) and a value. (-1 to stop): 4 40
Enter an offset (0-9) and a value. (-1 to stop): 5 40
Enter an offset (0-9) and a value. (-1 to stop): 6 60
Enter an offset (0-9) and a value. (-1 to stop): 7 70
Enter an offset (0-9) and a value. (-1 to stop): 8 80
Enter an offset (0-9) and a value. (-1 to stop): 9 90
Enter an offset (0-9) and a value. (-1 to stop): 10 10
****Please use values between 0 and 9. ***
Enter an offset (0-9) and a value. (-1 to stop): -1 -1

Here's the entire array:
[0] 0
[1] 10
[2] 20
[3] 30
[4] 40
[5] 40
[6] 60
[7] 70
[8] 80
[9] 90

