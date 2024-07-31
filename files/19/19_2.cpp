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
	// методи доступу
	int GetSize() { return itsSize; }

private:
	T *pType;
	int itsSize;
};

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
	Array<int> theArray;
	Array<Animal> theZoo;
	Animal *pAnimal;

	// заповнюємо масив
	for (int i = 0; i < theArray.GetSize(); i++)
	{
		theArray[i] = i * 2;
		pAnimal = new Animal(i * 3);
		theZoo[i] = *pAnimal;
		delete pAnimal;
	}
	// виводимо на друк вміст масиву
	for (int i = 0; i < theArray.GetSize(); i++)
	{
		cout << "theArray[" << i << "]:\t";
		cout << theArray[i] << "\t\t";
		cout << "theZoo[" << i << "]:\t";
		theZoo[i].Display();
		cout << endl;
	}

	return 0;
}
////
theArray[0]:    0               theZoo[0]:      0
theArray[1]:    2               theZoo[1]:      3
theArray[2]:    4               theZoo[2]:      6
theArray[3]:    6               theZoo[3]:      9
theArray[4]:    8               theZoo[4]:      12
theArray[5]:    10              theZoo[5]:      15
theArray[6]:    12              theZoo[6]:      18
theArray[7]:    14              theZoo[7]:      21
theArray[8]:    16              theZoo[8]:      24
theArray[9]:    18              theZoo[9]:      27

