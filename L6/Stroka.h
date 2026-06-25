#pragma once

// Класс для работы со строками
class Stroka
{
private:
    // Указатель на динамическую строку
    char* str;

    // Размер выделенной памяти
    int size;

public:

    // Конструктор по умолчанию
    Stroka();

    // Конструктор из C-строки
    Stroka(const char* text);

    // Конструктор с указанием размера памяти
    Stroka(int memorySize);

    // Конструктор копирования
    Stroka(const Stroka& other);

    // Деструктор
    ~Stroka();

    // Оператор присваивания
    Stroka& operator=(const Stroka& other);

    // Оператор сцепления строк
    Stroka operator+(const Stroka& other);

    // Оператор сравнения строк
    int operator==(const Stroka& other);

    // Определение длины строки
    int dlina();

    // Ввод строки
    void vvod();

    // Вывод строки
    void vyvod();
};