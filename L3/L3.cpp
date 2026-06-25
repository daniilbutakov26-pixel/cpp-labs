#include <iostream>

using namespace std;

// Вывод массива на экран
void printArray(int mas[], int n)
{
    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";

    cout << endl;
}

// Копирование одного массива в другой
void copyArray(int source[], int destination[], int n)
{
    for (int i = 0; i < n; i++)
        destination[i] = source[i];
}

// Сортировка методом мини-макса по возрастанию
void miniMaxSort(int mas[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int imin = i;

        for (int j = i + 1; j < n; j++)
            if (mas[j] < mas[imin])
                imin = j;

        int temp = mas[i];
        mas[i] = mas[imin];
        mas[imin] = temp;
    }
}

// Сортировка пузырьком по возрастанию
void bubbleSort(int mas[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}

// Быстрая сортировка по возрастанию
void quickSort(int mas[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = mas[(left + right) / 2];

    while (i <= j)
    {
        while (mas[i] < pivot)
            i++;

        while (mas[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = mas[i];
            mas[i] = mas[j];
            mas[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(mas, left, j);

    if (i < right)
        quickSort(mas, i, right);
}

// Сортировка чётных значений по возрастанию
// и нечётных значений по убыванию
void sortEvenOdd(int mas[], int n)
{
    // Сортировка чётных элементов по возрастанию
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mas[i] % 2 == 0 &&
                mas[j] % 2 == 0 &&
                mas[i] > mas[j])
            {
                int temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
            }
        }
    }

    // Сортировка нечётных элементов по убыванию
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (mas[i] % 2 != 0 &&
                mas[j] % 2 != 0 &&
                mas[i] < mas[j])
            {
                int temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
            }
        }
    }
}

// Сортировка части массива по возрастанию от индекса n1 до n2
void sortIntervalAsc(int mas[], int n1, int n2)
{
    for (int i = n1; i < n2; i++)
    {
        for (int j = i + 1; j <= n2; j++)
        {
            if (mas[i] > mas[j])
            {
                int temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
            }
        }
    }
}

// Сортировка части массива по убыванию от индекса n1 до n2
void sortIntervalDesc(int mas[], int n1, int n2)
{
    for (int i = n1; i < n2; i++)
    {
        for (int j = i + 1; j <= n2; j++)
        {
            if (mas[i] < mas[j])
            {
                int temp = mas[i];
                mas[i] = mas[j];
                mas[j] = temp;
            }
        }
    }
}

int main()
{
    // Исходный массив из методички
    int original[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };

    // Количество элементов массива
    int n = sizeof(original) / sizeof(int);

    // Рабочий массив, в который копируется исходный массив перед каждой сортировкой
    int mas[13];

    cout << "Original array:\n";
    printArray(original, n);

    // 1. Сортировка методом мини-макса
    copyArray(original, mas, n);
    miniMaxSort(mas, n);

    cout << "\n1. Mini-max sort ascending:\n";
    printArray(mas, n);

    // 2. Сортировка методом пузырька
    copyArray(original, mas, n);
    bubbleSort(mas, n);

    cout << "\n2. Bubble sort ascending:\n";
    printArray(mas, n);

    // 3. Быстрая сортировка
    copyArray(original, mas, n);
    quickSort(mas, 0, n - 1);

    cout << "\n3. Quick sort ascending:\n";
    printArray(mas, n);

    // 4. Чётные значения по возрастанию, нечётные по убыванию
    copyArray(original, mas, n);
    sortEvenOdd(mas, n);

    cout << "\n4. Even ascending, odd descending:\n";
    printArray(mas, n);

    // 5. Сортировка по возрастанию на интервале индексов
    copyArray(original, mas, n);

    // Индексы интервала. Можно изменить при необходимости.
    int n1 = 3;
    int n2 = 9;

    sortIntervalAsc(mas, n1, n2);

    cout << "\n5. Sort ascending from index " << n1 << " to " << n2 << ":\n";
    printArray(mas, n);

    // 6. Сортировка по убыванию на интервале индексов
    copyArray(original, mas, n);

    sortIntervalDesc(mas, n1, n2);

    cout << "\n6. Sort descending from index " << n1 << " to " << n2 << ":\n";
    printArray(mas, n);

    return 0;
}