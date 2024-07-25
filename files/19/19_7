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
	// cout << "animal(int) ";
}

Animal::Animal() : itsWeight(0)
{
	// cout << "animal() ";
}

Animal::~Animal()
{
	// cout << "Destroyed an animal...\n";
}

template <class T> // оголошуємо шаблон і параметр
class Array		   // параметризований клас
{
public:
	// конструктори
	Array(int itsSize = ::DefaultSize);
	Array(const Array &rhs);
	~Array()
	{
		delete[] pType;
		itsNumberArrays--;
	}
	// оператори
	Array &operator=(const Array &);
	T &operator[](int offSet) { return pType[offSet]; }
	const T &operator[](int offSet) const { return pType[offSet]; }
	// методи доступу
	int GetSize() const { return itsSize; }
	static int GetNumberArrays() { return itsNumberArrays; }

	// функція-друг
	template <typename U> // всі примірники цього шаблону є моїми друзями
	friend ostream &operator<<(ostream &, const Array<T> &);

private:
	T *pType;
	int itsSize;
	static int itsNumberArrays;
};

template <class T>
int Array<T>::itsNumberArrays = 0;

// Виконуємо кнструктор
template <class T>
Array<T>::Array(int size) : itsSize(size)
{
	pType = new T[size];
	for (int i = 0; i < size; i++)
		pType[i] = (T)0;
	itsNumberArrays++;
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
	itsNumberArrays++;
}

template <typename T>
ostream &operator<<(ostream &output, const Array<T> &theArray)
{
	for (int i = 0; i < theArray.GetSize(); i++)
		output << "[" << i << "] " << theArray[i] << endl;
	return output;
}

void IntFillFunction(Array<int> &theArray);
void AnimalFillFunction(Array<Animal> &theArray);

// виконуюча програ
int main()
{
	cout << Array<int>::GetNumberArrays() << " integer arrays\n";
	cout << Array<Animal>::GetNumberArrays();
	cout << " animal arrays\n\n";
	Array<int> intArray;
	Array<Animal> animalArray;

	cout << intArray.GetNumberArrays() << " integer arrays\n";
	cout << animalArray.GetNumberArrays();
	cout << " animal arrays\n\n";

	Array<int> *pIntArray = new Array<int>;
	cout << Array<int>::GetNumberArrays() << " integer arrays\n";
	cout << Array<Animal>::GetNumberArrays();
	cout << " animal arrays\n\n";

	delete pIntArray;

	cout << Array<int>::GetNumberArrays() << " integer arrays\n";
	cout << Array<Animal>::GetNumberArrays();
	cout << " animal arrays\n\n";

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
0 integer arrays
0 animal arrays

1 integer arrays
1 animal arrays

2 integer arrays
1 animal arrays

1 integer arrays
1 animal arrays

