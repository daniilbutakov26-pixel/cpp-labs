#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Функция определения длины строки
int myLength(char* str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    return len;
}

// Функция копирования строки
void myCopy(char* dest, char* src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
}

// Функция сравнения строк
int myCompare(char* str1, char* str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];

        i++;
    }

    return str1[i] - str2[i];
}

// Функция сцепления строк
void myConcat(char* dest, char* src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;

    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
}

// Вывод результата сравнения строк
void printCompareResult(int result)
{
    if (result == 0)
        cout << "Strings are equal" << endl;
    else if (result > 0)
        cout << "First string is greater" << endl;
    else
        cout << "Second string is greater" << endl;
}

int main()
{
    // ===============================
    // ПУНКТ 3. Динамическая память malloc
    // ===============================

    cout << "TASK 3. malloc\n";

    char* str1 = (char*)malloc(100 * sizeof(char));
    char* str2 = (char*)malloc(100 * sizeof(char));

    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    cout << "Length str1 = " << myLength(str1) << endl;
    cout << "Length str2 = " << myLength(str2) << endl;

    char* copyStr = (char*)malloc(100 * sizeof(char));
    myCopy(copyStr, str1);
    cout << "Copy str1 = " << copyStr << endl;

    cout << "Compare str1 and str2: ";
    printCompareResult(myCompare(str1, str2));

    myConcat(str1, str2);
    cout << "Concat str1 + str2 = " << str1 << endl;

    free(str1);
    free(str2);
    free(copyStr);

    // ===============================
    // ПУНКТ 4. Динамическая память calloc
    // ===============================

    cout << "\nTASK 4. calloc\n";

    char* cstr1 = (char*)calloc(100, sizeof(char));
    char* cstr2 = (char*)calloc(100, sizeof(char));

    strcpy(cstr1, "hello");
    strcpy(cstr2, "world");

    cout << "cstr1 = " << cstr1 << endl;
    cout << "cstr2 = " << cstr2 << endl;

    cout << "Length cstr1 = " << myLength(cstr1) << endl;
    cout << "Length cstr2 = " << myLength(cstr2) << endl;

    char* ccopyStr = (char*)calloc(100, sizeof(char));
    myCopy(ccopyStr, cstr1);
    cout << "Copy cstr1 = " << ccopyStr << endl;

    cout << "Compare cstr1 and cstr2: ";
    printCompareResult(myCompare(cstr1, cstr2));

    myConcat(cstr1, cstr2);
    cout << "Concat cstr1 + cstr2 = " << cstr1 << endl;

    free(cstr1);
    free(cstr2);
    free(ccopyStr);

    // ===============================
    // ПУНКТ 5. Массив строк
    // ===============================

    cout << "\nTASK 5. Array of strings\n";

    char strings[4][100] =
    {
        "qwerty",
        "1234567890",
        "student",
        "programming"
    };

    for (int i = 0; i < 4; i++)
    {
        cout << "\nString " << i + 1 << ": " << strings[i] << endl;
        cout << "Length = " << myLength(strings[i]) << endl;
    }

    cout << "\nCompare first and second string: ";
    printCompareResult(myCompare(strings[0], strings[1]));

    char result[200];

    myCopy(result, strings[0]);
    myConcat(result, strings[2]);

    cout << "Concat first and third string = " << result << endl;

    // ===============================
    // malloc и calloc
    // ===============================

    cout << "\nDifference between malloc and calloc:" << endl;
    cout << "malloc allocates memory but does not clear it." << endl;
    cout << "calloc allocates memory and fills it with zeros." << endl;

    return 0;
}