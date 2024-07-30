#include<iostream>

using namespace std;

template <class T> //шаблон класса с переменной Т
class List
{
public:
    List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(T value);
	void append(T value);
	bool is_present(T value) const;
	T is_empty() const
	{
    	return head == 0;
	}
	T count() const { return theCount; }
private:
	class ListCell
	{
	public:
    	ListCell(T value, ListCell *cell = 0) : val(value), next(cell) {}
    	T val;
    	ListCell *next;
	};
	T val;
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	T theCount;
};

//деструктор
template <typename T>
List<T>::~List()
{
	while (head != nullptr)
	{
		ListCell *temp = head;
		head = head->next;
		delete temp;
	}	
}

//вставка
template <typename T>
void List<T>::insert(T value)
{
    head = new ListCell(value, head);
    if (tail == nullptr)
    {
        tail = head;
    }
    ++theCount;
}

//добавление
template <typename T>
void List<T>::append(T value)
{
    ListCell *newCell = new ListCell(value);
    if (tail != nullptr)
    {
        tail->next = newCell;
    }
    else
    {
        head = newCell;
    }
    tail = newCell;
    ++theCount;
}

template <typename T>
bool List<T>::is_present(T value) const
{
    for (ListCell *cell = head; cell != nullptr; cell = cell->next)
    {
        if (cell->val == value)
        {
            return true;
        }
    }
    return false;
}

//класс Cat
class Cat
{
public:
    Cat(int age, int weight): itsAge(age), itsWeight(weight){}
    int GetAge() { return itsAge; }
    int GetWeight() { return itsWeight; }
private:
    int itsAge;
    int itsWeight;
};

List<string> people_names;
List<Cat> sum_cats;
List<int> sum_numbers;
int main()
{
    //создаем котиков ^_^
    Cat Tom(1,3);
    Cat Frosk(6,2.5);
    Cat Mus(0.5, 1);

    //добавляем в список
    sum_cats.append(Tom);
    sum_cats.append(Frosk);
    sum_cats.append(Mus);


    return 0;
}
//c