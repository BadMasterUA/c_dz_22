#include <iostream>
#include <string>
#include <list>

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

Student::Student(const Student &rhs) : itsName(rhs.GetName()), itsAge(rhs.GetAge())
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
class Print
{
public:
	void operator()(const T &t)
	{
		cout << t << endl;
	}
};

template <class T>
void ShowList(const list<T> &v); 

typedef list<Student> Class;

int main()
{
	Student Harry;
	Student Sally("Sally", 15);
	Student Bill("Bill", 17);
	Student Peter("Peter", 16);

	Class SchoolClass;
	// добавляем наших студентов в список класса
	// SchoolClass.push_back(Harry);
	SchoolClass.push_back(Sally);
	SchoolClass.push_back(Bill);
	SchoolClass.push_back(Peter);

	ShowList(SchoolClass);

	cout << endl;
	return 0;
}

template <class T>
void ShowList(const list<T> &v)
{
	Print<Student> PrintStudent;
	for (auto it : v)
		PrintStudent(it);
}
