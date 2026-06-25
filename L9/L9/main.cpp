#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// =======================================================
// ЛАБОРАТОРНАЯ РАБОТА 9
// Шаблоны функций и шаблоны классов
// =======================================================


// =======================================================
// ШАБЛОН СОРТИРОВКИ SORT
// Можно применять к int, double и пользовательским типам,
// если у них перегружен оператор >
// =======================================================

template <class T>
void Sort(T mas[], int n)
{
    // Простая сортировка выбором по возрастанию
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mas[i] > mas[j])
            {
                T temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
            }
        }
    }
}


// =======================================================
// ПОЛЬЗОВАТЕЛЬСКИЙ ТИП MONEY
// Нужен для демонстрации применения шаблона Sort
// к типу, созданному пользователем
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

    // Перегрузка оператора >
    // Без неё шаблон Sort не сможет сравнивать объекты Money
    bool operator>(const Money& amt) const
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


// =======================================================
// ПРИМЕРЫ 9.1.2 И 9.1.3
// Перегрузка и специализация шаблонных функций
// =======================================================

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

// Специализированная функция для C-строк.
// Обычный шаблон для char* сравнивал бы адреса, а не текст.
char* getmax(char* s1, char* s2)
{
    return strcmp(s1, s2) > 0 ? s1 : s2;
}


// =======================================================
// ШАБЛОН КЛАССА TSTACK
// Используется как тупик / стек для сортировки состава
// =======================================================

template <class T>
class TStack
{
private:
    T* data;       // динамический массив для хранения элементов
    int topIndex;  // индекс вершины стека
    int capacity;  // максимальный размер стека

public:
    // Конструктор создаёт стек заданного размера
    TStack(int size)
    {
        capacity = size;
        data = new T[capacity];
        topIndex = -1;
    }

    // Деструктор освобождает динамическую память
    ~TStack()
    {
        delete[] data;
    }

    // Проверка пустого стека
    bool isEmpty() const
    {
        return topIndex == -1;
    }

    // Проверка полного стека
    bool isFull() const
    {
        return topIndex == capacity - 1;
    }

    // Добавление элемента в стек
    void push(T value)
    {
        if (!isFull())
            data[++topIndex] = value;
    }

    // Извлечение элемента из стека
    T pop()
    {
        return data[topIndex--];
    }

    // Просмотр верхнего элемента без извлечения
    T top() const
    {
        return data[topIndex];
    }
};


// =======================================================
// ПУНКТ 1
// Применение шаблона Sort к пользовательскому типу Money
// =======================================================

void task1()
{
    cout << "\nTASK 1. Template Sort for user-defined type Money\n\n";

    Money mas[] =
    {
        Money(19, 10),
        Money(99, 99),
        Money(99, 95),
        Money(19, 95)
    };

    int n = sizeof(mas) / sizeof(mas[0]);

    cout << "Before sorting:\n";
    for (int i = 0; i < n; i++)
        cout << "mas[" << i << "] = " << mas[i] << endl;

    Sort(mas, n);

    cout << "\nAfter sorting:\n";
    for (int i = 0; i < n; i++)
        cout << "mas[" << i << "] = " << mas[i] << endl;
}


// =======================================================
// ПУНКТ 2
// Примеры перегрузки и специализации шаблонов функций
// =======================================================

void task2()
{
    cout << "\nTASK 2. Function templates getmax\n\n";

    int i1 = 3, i2 = 5;
    double d1 = 3.14, d2 = 2.71;

    int intMas[] = { 3, 9, 5, 8 };
    double doubleMas[] = { 1.5, 7.2, 3.3, 4.8 };

    char s1[] = "stroka1";
    char s2[] = "stroka2";

    cout << "Max int = " << getmax(i1, i2) << endl;
    cout << "Max double = " << getmax(d1, d2) << endl;

    cout << "Max int array = "
        << getmax(intMas, sizeof(intMas) / sizeof(intMas[0]))
        << endl;

    cout << "Max double array = "
        << getmax(doubleMas, sizeof(doubleMas) / sizeof(doubleMas[0]))
        << endl;

    cout << "Max string = " << getmax(s1, s2) << endl;
}


// =======================================================
// ПУНКТ 3
// Сортировка железнодорожного состава с использованием тупика.
// Тупик реализован через шаблон класса TStack.
// Программа пытается получить состав в порядке убывания.
// Пример: вход 1 5 3 -> выход 5 3 1
// =======================================================

bool railwaySort(const vector<int>& input, vector<int>& output)
{
    vector<int> target = input;

    // Требуемый порядок выхода: по убыванию
    sort(target.begin(), target.end(), greater<int>());

    TStack<int> siding((int)input.size());

    int targetPos = 0;

    for (int value : input)
    {
        // Если текущий вагон нужен прямо сейчас, отправляем его на выход
        if (value == target[targetPos])
        {
            output.push_back(value);
            targetPos++;
        }
        else
        {
            // Иначе отправляем вагон в тупик
            siding.push(value);
        }

        // После каждого действия проверяем, можно ли вывести вагоны из тупика
        while (!siding.isEmpty() && targetPos < (int)target.size() &&
            siding.top() == target[targetPos])
        {
            output.push_back(siding.pop());
            targetPos++;
        }
    }

    // Если удалось вывести все вагоны, сортировка возможна
    return output.size() == input.size();
}

void task3()
{
    cout << "\nTASK 3. Railway sorting using TStack\n\n";

    int n;

    cout << "Enter number of wagons: ";
    cin >> n;

    vector<int> input(n);

    cout << "Enter wagon numbers:\n";
    for (int i = 0; i < n; i++)
        cin >> input[i];

    vector<int> output;

    bool success = railwaySort(input, output);

    cout << "\nInput train:\n";
    for (int value : input)
        cout << value << " ";

    cout << "\n\nOutput train:\n";
    for (int value : output)
        cout << value << " ";

    if (success)
        cout << "\n\nSorting completed successfully." << endl;
    else
        cout << "\n\nThis train cannot be sorted using one siding stack." << endl;
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
        cout << "LABORATORY WORK 9\n";
        cout << "1 - Sort template for Money\n";
        cout << "2 - getmax template examples\n";
        cout << "3 - Railway sorting with TStack\n";
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
