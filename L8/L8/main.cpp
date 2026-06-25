#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

// =======================================================
// ЛАБОРАТОРНАЯ РАБОТА 8
// Работа с потоками C++
// =======================================================


// =======================================================
// ПУНКТ 1. Класс Stroka с перегрузкой >> и <<
// =======================================================

class Stroka
{
private:
    char str[80];

public:
    // Конструктор по умолчанию
    Stroka()
    {
        str[0] = '\0';
    }

    // Конструктор из обычной C-строки
    Stroka(const char* text)
    {
        strcpy(str, text);
    }

    // Метод определения длины строки
    int dlina()
    {
        return strlen(str);
    }

    // Перегрузка оператора ввода
    friend istream& operator>>(istream& in, Stroka& s)
    {
        in >> s.str;
        return in;
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& out, const Stroka& s)
    {
        out << s.str;
        return out;
    }
};


// =======================================================
// ПУНКТ 2. Класс Money и шаблонные функции
// =======================================================

class Money
{
private:
    long dollars;
    int cents;

public:
    // Конструктор по умолчанию
    Money()
    {
        dollars = 0;
        cents = 0;
    }

    // Конструктор с параметрами
    Money(long d, int c)
    {
        dollars = d;
        cents = c;
    }

    // Перегрузка оператора сравнения >
    int operator>(const Money& amt) const
    {
        return dollars > amt.dollars ||
            (dollars == amt.dollars && cents > amt.cents);
    }

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Money& amt)
    {
        os << "$" << amt.dollars << ".";

        if (amt.cents < 10)
            os << "0";

        os << amt.cents;

        return os;
    }
};

// Шаблонная функция возвращает больший из двух параметров
template <class T>
T getmax(T t1, T t2)
{
    return t1 > t2 ? t1 : t2;
}

// Шаблонная функция возвращает максимальный элемент массива
template <class T>
T getmax(T t[], size_t size)
{
    T retval = t[0];

    for (size_t i = 1; i < size; i++)
        if (t[i] > retval)
            retval = t[i];

    return retval;
}

// Отдельная перегрузка для C-строк
char* getmax(char* s1, char* s2)
{
    return strcmp(s1, s2) > 0 ? s1 : s2;
}

// Сортировка массива Money по возрастанию
void Sort(Money mas[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mas[i] > mas[j])
            {
                Money temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
            }
        }
    }
}


// =======================================================
// ПУНКТ 3. Шифратор через ifstream/ofstream
// =======================================================

// Функция шифрует или расшифровывает файл.
// Повторный запуск с тем же ключом восстанавливает исходный файл.
void encryptFile(const string& inputFile, const string& outputFile, const string& key)
{
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in || !out)
    {
        cout << "File error!" << endl;
        return;
    }

    char ch;
    int keyPos = 0;

    while (in.get(ch))
    {
        ch = ch ^ key[keyPos];
        out.put(ch);

        keyPos++;

        if (keyPos >= (int)key.length())
            keyPos = 0;
    }

    in.close();
    out.close();

    cout << "Done. Output file: " << outputFile << endl;
}


// =======================================================
// ПУНКТ 4. Состояния потоков
// =======================================================

void checkStreamStates(const string& fileName)
{
    ifstream file(fileName);

    // good() показывает, что поток находится в нормальном состоянии
    if (file.good())
        cout << "Stream state: good()" << endl;

    // fail() показывает ошибку открытия или чтения
    if (file.fail())
    {
        cout << "Stream state: fail()" << endl;
        cout << "File was not opened." << endl;
        return;
    }

    string line;

    cout << "\nFile content:\n";

    while (getline(file, line))
        cout << line << endl;

    // eof() показывает, что достигнут конец файла
    if (file.eof())
        cout << "\nStream state: eof()" << endl;

    // clear() очищает флаги состояния потока
    file.clear();

    if (file.good())
        cout << "After clear(): stream is good again." << endl;

    file.close();
}


// =======================================================
// ФУНКЦИИ ДЛЯ ЗАПУСКА ОТДЕЛЬНЫХ ПУНКТОВ
// =======================================================

void task1()
{
    cout << "\nTASK 1. Stroka stream operators\n";

    Stroka s1;

    cout << "Enter string: ";
    cin >> s1;

    cout << "You entered: " << s1 << endl;
    cout << "Length = " << s1.dlina() << endl;
}

void task2()
{
    cout << "\nTASK 2. Money and templates\n";

    Money mas[] =
    {
        Money(19, 10),
        Money(99, 99),
        Money(99, 95),
        Money(19, 95)
    };

    int n = sizeof(mas) / sizeof(mas[0]);

    Sort(mas, n);

    cout << "Sorted money array:" << endl;

    for (int i = 0; i < n; i++)
        cout << "mas[" << i << "] = " << mas[i] << endl;

    int i1 = 3, i2 = 5;
    int intMas[] = { 3, 9, 5, 8 };

    cout << "\nMax int = " << getmax(i1, i2) << endl;
    cout << "Max array int = " << getmax(intMas, 4) << endl;

    char s1[] = "stroka1";
    char s2[] = "stroka2";

    cout << "Max string = " << getmax(s1, s2) << endl;
}

void task3()
{
    cout << "\nTASK 3. File encryption using streams\n";

    string inputFile;
    string outputFile;
    string key;

    cout << "Input file: ";
    cin >> inputFile;

    cout << "Output file: ";
    cin >> outputFile;

    cout << "Key: ";
    cin >> key;

    encryptFile(inputFile, outputFile, key);
}

void task4()
{
    cout << "\nTASK 4. Stream states\n";

    string fileName;

    cout << "Enter file name: ";
    cin >> fileName;

    checkStreamStates(fileName);
}


// =======================================================
// ГЛАВНАЯ ФУНКЦИЯ
// =======================================================

int main()
{
    int choice;

    do
    {
        cout << "\n==============================\n";
        cout << "LABORATORY WORK 8\n";
        cout << "1 - Stroka input/output operators\n";
        cout << "2 - Money and template examples\n";
        cout << "3 - File encryptor\n";
        cout << "4 - Stream state methods\n";
        cout << "0 - Exit\n";
        cout << "Choose task: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        case 4:
            task4();
            break;

        case 0:
            cout << "Exit." << endl;
            break;

        default:
            cout << "Wrong choice!" << endl;
            break;
        }

    } while (choice != 0);

    // Пауза, чтобы консоль не закрывалась сразу
    system("pause");

    return 0;
}
