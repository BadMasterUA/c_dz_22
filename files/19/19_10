#include <iostream>
#include <string>
#include <map>
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

Student::Student(const Student &rhs) : itsName(rhs.GetName()),
									   itsAge(rhs.GetAge())
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

template <class T, class A>
void ShowMap(const map<T, A> &v); // Відображає властивості мапи

typedef map<string, Student> SchoolClass;

int main()
{
	Student Harry("Harry", 18);
	Student Sally("Sally", 15);
	Student Bill("Bill", 17);
	Student Peter("Peter", 16);
	SchoolClass MathClass;
	MathClass[Harry.GetName()] = Harry;
	MathClass[Sally.GetName()] = Sally;
	MathClass[Bill.GetName()] = Bill;
	MathClass[Peter.GetName()] = Peter;
	cout << "MathClass:\n";
	ShowMap(MathClass);

	cout << "We known that " << MathClass["Bill"].GetName() << " is " << MathClass["Bill"].GetAge() << " years old\n";

	return 0;
}

//
// Відображає властивості карти
//
template <class T, class A>
void ShowMap(const map<T, A> &v)
{
	for (auto ci = v.begin(); ci != v.end(); ++ci)
		cout << ci->first << ": " << ci->second << "\n";
	cout << endl;
}

////
MathClass:
Bill: Bill is 17 years old
Harry: Harry is 18 years old
Peter: Peter is 16 years old
Sally: Sally is 15 years old

We known that Bill is 17 years old

