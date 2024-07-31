#include <iostream>
using namespace std;

const int DefaultSize = 10;

// звичайний клас Animal для
// створення масиву тварин

class Animal
{
public:
	Animal(int);
	Animal();
	~Animal() {}
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
}

Animal::Animal() : itsWeight(0)
{
}

template <class T> // оголошуємо шаблон і параметр
class Array		   // параметризований клас
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
	template <typename U> // всі примірники цього шаблону є моїми друзями
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

// Виконуємо кнструктор
template <class T>
Array<T>::Array(int size) : itsSize(size)
{
	pType = new T[size];
	for (int i = 0; i < size; i++)
		pType[i] = 0;
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
Enter an offset (0-9)and a value. (-1 to stop): 1 10
Enter an offset (0-9)and a value. (-1 to stop): 2 20
Enter an offset (0-9)and a value. (-1 to stop): 3 30
Enter an offset (0-9)and a value. (-1 to stop): 4 40
Enter an offset (0-9)and a value. (-1 to stop): 5 50
Enter an offset (0-9)and a value. (-1 to stop): 6 60
Enter an offset (0-9)and a value. (-1 to stop): 7 70
Enter an offset (0-9)and a value. (-1 to stop): 8 80 
Enter an offset (0-9)and a value. (-1 to stop): 9 90
Enter an offset (0-9)and a value. (-1 to stop): 10 10
****Please use values ...between 0 and 9. ***
Enter an offset (0-9)and a value. (-1 to stop): -1 -1
intArray...
[0] 0
[1] 10
[2] 20
[3] 30
[4] 40
[5] 50
[6] 60
[7] 70
[8] 80
[9] 90

animalArray...
[0] 0
[1] 100
[2] 200
[3] 300
[4] 400
[5] 500
[6] 600
[7] 700
[8] 800
[9] 900

