#include <iostream>
#include "Stroka.h"

using namespace std;

int main()
{
    // Создание строки через конструктор
    Stroka s1("qwert");

    // Создание пустой строки
    Stroka s3;

    // Создание строки через конструктор копирования
    Stroka s4(s1);

    // Ещё одна пустая строка
    Stroka s5;

    cout << "Enter string for s3: ";

    // Ввод строки
    s3.vvod();

    // Демонстрация оператора присваивания
    s3 = "asdfg";

    cout << "\ns3 = ";

    s3.vyvod();

    cout << endl;

    // Демонстрация оператора сложения
    s5 = s1 + s3 + s4;

    cout << "\nLength s5 = "
        << s5.dlina()
        << endl;

    cout << "s5 = ";

    s5.vyvod();

    cout << endl;

    // Проверка сравнения строк
    if (s1 == s5)
    {
        cout << "Strings s1 and s5 are equal"
            << endl;
    }
    else if (s1 == s4)
    {
        cout << "Strings s1 and s4 are equal"
            << endl;
    }

    return 0;
}