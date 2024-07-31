#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Student
{
public:
	Student();
	Student(const string &name, const int age);
	Student(const Student &rhs);
	~Student();

	void SetName(const string &name);
	string GetName() const;
	void SetAge(const int age);
	int GetAge() const;
	Student &operator=(const Student &rhs);

	void operator()(const Student &t)
	{
		cout << t << " ";
	} 

private:
	string itsName;
	int itsAge;
};

Student::Student()
	: itsName("New Student"), itsAge(16)
{
}

Student::Student(const string &name, const int age) : itsName(name), itsAge(age)
{
}

Student::Student(const Student &rhs) : itsName(rhs.GetName()),itsAge(rhs.GetAge())
{
}

Student::~Student()
{
}

void Student::SetName(const string &name)
{
	itsName = name;
}

string Student::GetName() const
{
	return itsName;
}

void Student::SetAge(const int age)
{
	itsAge = age;
}

int Student::GetAge() const
{
	return itsAge;
}

Student &Student::operator=(const Student &rhs)
{
	itsName = rhs.GetName();
	itsAge = rhs.GetAge();
	return *this;
}

ostream &operator<<(ostream &os, const Student &rhs)
{
	os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
	return os;
}

template <class T>
void ShowVector(const vector<T> &v); // Відображає властивості вектора



typedef list<Student> Class;

int main()
{
	Student Harry;
	Student Sally("Sally", 15);
	Student Bill("Bill", 17);
	Student Peter("Peter", 16);

	Class SchoolClass;
	//{
	/*public:
		void operator()(const Student &t)
		{
			cout << t << " ";
		}*/
	//};
	//добавляем наших студентов в список класса
	//SchoolClass.push_back(Harry);
	SchoolClass.push_back(Sally);
	SchoolClass.push_back(Bill);
	SchoolClass.push_back(Peter);

	//вывод содержимого списка
	for(auto it = SchoolClass.begin(); it != SchoolClass.end(); it++)
	{
		cout << *it << endl;
	}

	//увеличеваем возрост учеников
	for(auto it = SchoolClass.begin(); it != SchoolClass.end(); it++)
	{
		it->SetAge(2);
	}

	//вывод содержимого списка
	for(auto it = SchoolClass.begin(); it != SchoolClass.end(); it++)
	{
		cout << *it << endl;
	}

	//вывод при помощи обьекта 
	for(int i = 0; i < SchoolClass.size(); ++i)
	{
		SchoolClass(i);
	}
	cout << endl;
	return 0;
}

//
// Відображає властивості вектора
//
template <class T>
void ShowVector(const vector<T> &v)
{
	cout << "max_size() = " << v.max_size();
	cout << "\tsize() = " << v.size();
	cout << "\tcapacity() = " << v.capacity();
	cout << "\t " << (v.empty() ? "empty" : "not empty");
	cout << "\n";
	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << "\n";
	cout << endl;
}
/*
EmptyClass:
max_size() = 576460752303423487 size() = 0      capacity() = 0   empty

GrowingClass(3):
max_size() = 576460752303423487 size() = 3      capacity() = 3   not empty
New Student is 16 years old
New Student is 16 years old
New Student is 16 years old

GrowingClass(3) after assigning students:
max_size() = 576460752303423487 size() = 3      capacity() = 3   not empty
New Student is 16 years old
Sally is 15 years old
Bill is 17 years old

GrowingClass() after aded 4ht student:
max_size() = 576460752303423487 size() = 4      capacity() = 6   not empty
New Student is 16 years old
Sally is 15 years old
Bill is 17 years old
Peter is 16 years old

GrowingClass() after Set:
max_size() = 576460752303423487 size() = 4      capacity() = 6   not empty
Harry is 18 years old
Sally is 15 years old
Bill is 17 years old
Peter is 16 years old

*/