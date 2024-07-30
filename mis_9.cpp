#include<iostream>

using namespace std;

//создаем шаблон
template<typename T>
void swap(T& a, T& b)
{
    T temp = a; // создвем обьект для временного хранения значений а
    a = b; // присваеваем значения a переменной b
    b = temp; // значения из temp присваеваем перемменой b
}

int main()
{
    int x = 10;
    int y = 10;

    //значения до обменна
    cout << "bef. swap: x = " << x << ", y = " << y << "\n";

    swap(x,y); // меняем местами (не мойму вчем проблема)
    
    cout << "aft. swap: x = " << x << ", y = " << y << "\n";

    return 0;
    
}