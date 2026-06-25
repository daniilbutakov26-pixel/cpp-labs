#include <iostream>
#include <cstring>

using namespace std;

// Способ 1. Подсчёт длины через индекс
int dlina1(char* str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return len;
}

// Способ 2. Подсчёт длины через указатель
int dlina2(char* str)
{
    char* p = str;

    while (*p != '\0')
        p++;

    return p - str;
}

// Способ 3. Рекурсивное определение длины строки
int dlina3(char* str)
{
    if (*str == '\0')
        return 0;

    return 1 + dlina3(str + 1);
}

// Собственное копирование строки
void kopir(char* dest, char* src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

// Собственное сравнение строк
void sravn(char* str1, char* str2)
{
    int result = 0;

    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            result = *str1 - *str2;
            break;
        }

        str1++;
        str2++;
    }

    if (result == 0)
        result = *str1 - *str2;

    if (result == 0)
        cout << "Strings are equal" << endl;
    else if (result > 0)
        cout << "First string is greater" << endl;
    else
        cout << "Second string is greater" << endl;
}

// Собственное сцепление строк
void konkat(char* dest, char* src)
{
    while (*dest != '\0')
        dest++;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int main()
{
    char str1[100] = "qwerty";
    char str2[100] = "1234567890";

    cout << "Original strings:" << endl;
    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    // ===== БИБЛИОТЕЧНЫЕ ФУНКЦИИ =====

    cout << "\n--- Standard functions ---" << endl;

    cout << "strlen(str1) = " << strlen(str1) << endl;
    cout << "strlen(str2) = " << strlen(str2) << endl;

    char copy1[100];
    strcpy(copy1, str1);
    cout << "strcpy result: " << copy1 << endl;

    cout << "strcmp result = "
        << strcmp(str1, str2)
        << endl;

    char concat1[100] = "qwerty";
    strcat(concat1, str2);
    cout << "strcat result: " << concat1 << endl;

    // ===== СОБСТВЕННЫЕ ФУНКЦИИ =====

    cout << "\n--- Custom functions ---" << endl;

    cout << "dlina1(str1) = "
        << dlina1(str1)
        << endl;

    cout << "dlina2(str1) = "
        << dlina2(str1)
        << endl;

    cout << "dlina3(str1) = "
        << dlina3(str1)
        << endl;

    char copy2[100];
    kopir(copy2, str1);

    cout << "kopir result: "
        << copy2
        << endl;

    cout << "sravn result: ";
    sravn(str1, str2);

    char concat2[100] = "qwerty";

    konkat(concat2, str2);

    cout << "konkat result: "
        << concat2
        << endl;

    return 0;
}