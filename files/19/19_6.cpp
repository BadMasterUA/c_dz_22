#include <iostream>
using namespace std;

const int DefaultSize = 3;

// звичайний клас Animal для
// створення масиву тварин

class Animal
{
public:
	Animal(int);
	Animal();
	~Animal();
	int GetWeight() const { return itsWeight; }
	void SetWeight(int theWeight) { itsWeight = theWeight; }

	friend ostream &operator<<(ostream &, const Animal &);

private:
	int itsWeight;
};

// оператор виведення об'єктів типу Animal
ostream &operator<<(ostream &theStream, const Animal &theAnimal)
{
	theStream << theAnimal.GetWeight();
	return theStream;
}

Animal::Animal(int weight) : itsWeight(weight)
{
	cout << "animal(int) ";
}

Animal::Animal() : itsWeight(0)
{
	cout << "animal() ";
}

Animal::~Animal()
{
	cout << "Destroyed an animal...\n";
}

template <class T> // оголошуємо шаблон і параметр
class Array		   // параметризований клас
{
public:
	// конструктори
	Array(int itsSize = ::DefaultSize);
	Array(const Array &rhs);
	~Array() { delete[] pType; }
	// оператори
	Array &operator=(const Array &);
	T &operator[](int offSet) { return pType[offSet]; }
	const T &operator[](int offSet) const { return pType[offSet]; }
	// методи доступу
	int GetSize() const { return itsSize; }
	// функція-друг
	template <typename U> // всі примірники цього шаблону є моїми друзями
	friend ostream &operator<<(ostream &, const Array<T> &);

private:
	T *pType;
	int itsSize;
};

// Виконуємо кнструктор
template <class T>
Array<T>::Array(int size) : itsSize(size)
{
	pType = new T[size];
	for (int i = 0; i < size; i++)
		pType[i] = (T)0;
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

// Конструктор-копіювальник
template <class T>
Array<T>::Array(const Array &rhs)
{
	itsSize = rhs.GetSize();
	pType = new T[itsSize];
	for (int i = 0; i < itsSize; i++)
		pType[i] = rhs[i];
}

template <typename T>
ostream &operator<<(ostream &output, const Array<T> &theArray)
{
	for (int i = 0; i < theArray.GetSize(); i++)
		output << "[" << i << "] " << theArray[i] << endl;
	return output;
}

// template<>
// Array<Animal>::Array(int AnimalArraySize) : itsSize(AnimalArraySize)
// {
// 	pType = new Animal[AnimalArraySize];
// }

void IntFillFunction(Array<int> &theArray);
void AnimalFillFunction(Array<Animal> &theArray);

// виконуюча програ
int main()
{
	Array<int> intArray;
	Array<Animal> animalArray;
	IntFillFunction(intArray);
	AnimalFillFunction(animalArray);
	cout << "intArray...\n"
		 << intArray;
	cout << "\nanimalArray...\n"
		 << animalArray << endl;
	return 0;
}

void IntFillFunction(Array<int> &theArray)
{
	bool Stop = false;
	int offset, value;
	while (!Stop)
	{
		cout << "Enter an offset (0-9)";
		cout << "and a value. (-1 to stop): ";
		cin >> offset >> value;
		if (offset < 0)
			break;
		if (offset > 9)
		{
			cout << "****Please use values ...between 0 and 9. ***\n";
			continue;
		}
		theArray[offset] = value;
	}
}

void AnimalFillFunction(Array<Animal> &theArray)
{
	Animal *pAnimal;
	for (int i = 0; i < theArray.GetSize(); i++)
	{
		pAnimal = new Animal;
		pAnimal->SetWeight(i * 100);
		theArray[i] = *pAnimal;
		delete pAnimal; // копія була поміщена в масив
	}
}
////
animal() animal() animal() Enter an offset (0-9)and a value. (-1 to stop): 0 0
Enter an offset (0-9)and a value. (-1 to stop): 1 1
Enter an offset (0-9)and a value. (-1 to stop): 2 2
Enter an offset (0-9)and a value. (-1 to stop): 3 3
Enter an offset (0-9)and a value. (-1 to stop): -1 -1
animal() Destroyed an animal...
animal() Destroyed an animal...
animal() Destroyed an animal...
intArray...
[0] 0
[1] 1
[2] 2

animalArray...
[0] 0
[1] 100
[2] 200

Destroyed an animal...
Destroyed an animal...
Destroyed an animal...
<<< Second RUN >>>
animal() animal() animal() animal(int) Destroyed an animal...
animal(int) Destroyed an animal...
animal(int) Destroyed an animal...
Enter an offset (0-9)and a value. (-1 to stop): 0 0
Enter an offset (0-9)and a value. (-1 to stop): 1 1
Enter an offset (0-9)and a value. (-1 to stop): 2 2
Enter an offset (0-9)and a value. (-1 to stop): 3 3
Enter an offset (0-9)and a value. (-1 to stop): -1 -1
animal() Destroyed an animal...
animal() Destroyed an animal...
animal() Destroyed an animal...
intArray...
[0] 0
[1] 1
[2] 2

animalArray...
[0] 0
[1] 100
[2] 200

Destroyed an animal...
Destroyed an animal...
Destroyed an animal...
////
