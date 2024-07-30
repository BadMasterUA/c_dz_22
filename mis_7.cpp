#include<iostream>

//template <class T> //шаблон класса с переменной Т
class List
{
public:
    List() : head(0), tail(0), theCount(0) {}
	virtual ~List();
	void insert(int value);
	void append(int value);
	bool is_present(int value) const;
	int is_empty() const
	{
    	return head == 0;
	}
	int count() const { return theCount; }

    //объявляем дружественный класс
    friend bool operator==(const List& lhs, const List& rhs);

private:
	class ListCell
	{
	public:
    	ListCell(int value, ListCell *cell = 0) : val(value), next(cell) {}
    	int val;
    	ListCell *next;
	};
	int val;
	ListCell *next;
	ListCell *head;
	ListCell *tail;
	int theCount;
};

//деструктор
List::~List()
{
	while (head != nullptr)
	{
		ListCell *temp = head;
		head = head->next;
		delete temp;
	}	
}

//вставка
void List::insert(int value)
{
    head = new ListCell(value, head);
    if (tail == nullptr)
    {
        tail = head;
    }
    ++theCount;
}

//добавление
void List::append(int value)
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

//
bool List::is_present(int value) const
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
//сровнение на равенство двух списков
bool operator==(const List& lhs, const List& rhs)
{
    if (lhs.theCount != rhs.theCount)
        return false;

    List::ListCell* currentLhs = lhs.head;
    List::ListCell* currentRhs = rhs.head;

    while (currentLhs != nullptr && currentRhs != nullptr)
    {
        if (currentLhs->val != currentRhs->val)
            return false;

        currentLhs = currentLhs->next;
        currentRhs = currentRhs->next;
    }

    return currentLhs == nullptr && currentRhs == nullptr;
}
int main()
{
    return 0;
}
