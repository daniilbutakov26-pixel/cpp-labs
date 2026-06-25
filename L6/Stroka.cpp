#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "Stroka.h"

using namespace std;

// Конструктор по умолчанию
// Создаёт пустую строку длиной 80 символов
Stroka::Stroka()
{
    size = 80;
    str = new char[size];
    str[0] = '\0';
}

// Конструктор из готовой строки
Stroka::Stroka(const char* text)
{
    size = strlen(text) + 1;

    str = new char[size];

    strcpy(str, text);
}

// Конструктор с заданным размером памяти
Stroka::Stroka(int memorySize)
{
    size = memorySize;

    str = new char[size];

    str[0] = '\0';
}

// Конструктор копирования
Stroka::Stroka(const Stroka& other)
{
    size = other.size;

    str = new char[size];

    strcpy(str, other.str);
}

// Деструктор освобождает динамическую память
Stroka::~Stroka()
{
    delete[] str;
}

// Перегруженный оператор присваивания
Stroka& Stroka::operator=(const Stroka& other)
{
    // Проверка на самоприсваивание
    if (this != &other)
    {
        delete[] str;

        size = other.size;

        str = new char[size];

        strcpy(str, other.str);
    }

    return *this;
}

// Перегруженный оператор сложения строк
Stroka Stroka::operator+(const Stroka& other)
{
    // Создаём новую строку нужного размера
    Stroka result(strlen(str) + strlen(other.str) + 1);

    // Копируем первую строку
    strcpy(result.str, str);

    // Добавляем вторую строку
    strcat(result.str, other.str);

    return result;
}

// Перегруженный оператор сравнения
int Stroka::operator==(const Stroka& other)
{
    return strcmp(str, other.str) == 0;
}

// Определение длины строки
int Stroka::dlina()
{
    return strlen(str);
}

// Ввод строки с клавиатуры
void Stroka::vvod()
{
    cin >> str;
}

// Вывод строки на экран
void Stroka::vyvod()
{
    cout << str;
}