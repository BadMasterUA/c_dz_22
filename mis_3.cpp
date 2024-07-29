#include<iostream>

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
int main()
{
    return 0;
}