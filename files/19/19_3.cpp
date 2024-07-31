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
	friend void Intrude(Array<int>);

private:
	T *pType;
	int itsSize;
};

// Оскільки функція - друг не являється шаблоном, її можна використовувати тільки
// з масивами цілих чисел! Але вона отримує доступ до закритих даних класу
void Intrude(Array<int> theArray)
{
	cout << "\n*** Intrude ***\n";
	for (int i = 0; i < theArray.itsSize; i++)
		cout << "i: " << theArray.pType[i] << endl;
	cout << endl;
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
		cout << "theZoo[" << i << "]:\t";
		theZoo[i].Display();
		cout << endl;
	}

	cout << "Now use the friend function to";
	cout << "find the members of Array<int>";
	Intrude(theArray);

	cout << "\n\nDone.\n";
	return 0;
}
////
theZoo[0]:      0
theZoo[1]:      3
theZoo[2]:      6
theZoo[3]:      9
theZoo[4]:      12
theZoo[5]:      15
theZoo[6]:      18
theZoo[7]:      21
theZoo[8]:      24
theZoo[9]:      27
Now use the friend function tofind the members of Array<int>
*** Intrude ***
i: 0
i: 2
i: 4
i: 6
i: 8
i: 10
i: 12
i: 14
i: 16
i: 18



Done.

