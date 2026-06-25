#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

// Размер квадратной матрицы
const int N = 5;

int main()
{
    // Объявление матрицы
    float m[N][N];

    // Заполнение матрицы случайными числами от 0 до 99
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = rand() % 100;

    // Вывод матрицы на экран
    cout << "Matrix:\n";
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << setw(8) << fixed << setprecision(2) << m[i][j];
        cout << endl;
    }

    // Начальные значения для поиска минимумов и максимумов
    float minMatrix = m[0][0], maxMatrix = m[0][0];
    float minMain = m[0][0], maxMain = m[0][0];
    float minSecond = m[0][N - 1], maxSecond = m[0][N - 1];

    float minUpper = m[0][0], maxUpper = m[0][0];
    float minLower = m[0][0], maxLower = m[0][0];

    // Суммы элементов матрицы и её треугольных частей
    float sumMatrix = 0;
    float sumUpper = 0, sumLower = 0;

    // Количество элементов в треугольных частях
    int countUpper = 0, countLower = 0;

    // Основной обход всех элементов матрицы
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            float value = m[i][j];

            // Минимум и максимум всей матрицы
            if (value < minMatrix) minMatrix = value;
            if (value > maxMatrix) maxMatrix = value;

            // Сумма всех элементов матрицы
            sumMatrix += value;

            // Главная диагональ: элементы, где номер строки равен номеру столбца
            if (i == j)
            {
                if (value < minMain) minMain = value;
                if (value > maxMain) maxMain = value;
            }

            // Побочная диагональ: элементы, где сумма индексов равна N - 1
            if (i + j == N - 1)
            {
                if (value < minSecond) minSecond = value;
                if (value > maxSecond) maxSecond = value;
            }

            // Верхнетреугольная часть матрицы, включая главную диагональ
            if (j >= i)
            {
                if (value < minUpper) minUpper = value;
                if (value > maxUpper) maxUpper = value;

                sumUpper += value;
                countUpper++;
            }

            // Нижнетреугольная часть матрицы, включая главную диагональ
            if (i >= j)
            {
                if (value < minLower) minLower = value;
                if (value > maxLower) maxLower = value;

                sumLower += value;
                countLower++;
            }
        }
    }

    // Средние значения
    float avgMatrix = sumMatrix / (N * N);
    float avgUpper = sumUpper / countUpper;
    float avgLower = sumLower / countLower;

    // Поиск элемента, ближайшего к среднему значению матрицы
    float closest = m[0][0];
    float minDiff = abs(m[0][0] - avgMatrix);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            float diff = abs(m[i][j] - avgMatrix);

            if (diff < minDiff)
            {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }

    // Вывод общих результатов
    cout << "\nMinimum matrix = " << minMatrix << endl;
    cout << "Maximum matrix = " << maxMatrix << endl;

    cout << "\nMinimum main diagonal = " << minMain << endl;
    cout << "Maximum main diagonal = " << maxMain << endl;

    cout << "\nMinimum secondary diagonal = " << minSecond << endl;
    cout << "Maximum secondary diagonal = " << maxSecond << endl;

    cout << "\nMinimum upper triangle = " << minUpper << endl;
    cout << "Maximum upper triangle = " << maxUpper << endl;

    cout << "\nMinimum lower triangle = " << minLower << endl;
    cout << "Maximum lower triangle = " << maxLower << endl;

    cout << "\nAverage matrix = " << avgMatrix << endl;
    cout << "Average upper triangle = " << avgUpper << endl;
    cout << "Average lower triangle = " << avgLower << endl;

    cout << "\nSum upper triangle = " << sumUpper << endl;
    cout << "Sum lower triangle = " << sumLower << endl;

    cout << "\nClosest to average = " << closest << endl;

    // Обработка строк матрицы
    cout << "\nRows:\n";
    for (int i = 0; i < N; i++)
    {
        float rowSum = 0;
        float rowMin = m[i][0];
        float rowMax = m[i][0];

        // Поиск суммы, минимума и максимума строки
        for (int j = 0; j < N; j++)
        {
            rowSum += m[i][j];

            if (m[i][j] < rowMin) rowMin = m[i][j];
            if (m[i][j] > rowMax) rowMax = m[i][j];
        }

        cout << "Row " << i + 1
            << ": sum = " << rowSum
            << ", min = " << rowMin
            << ", max = " << rowMax
            << ", average = " << rowSum / N
            << endl;
    }

    // Обработка столбцов матрицы
    cout << "\nColumns:\n";
    for (int j = 0; j < N; j++)
    {
        float colSum = 0;
        float colMin = m[0][j];
        float colMax = m[0][j];

        // Поиск суммы, минимума и максимума столбца
        for (int i = 0; i < N; i++)
        {
            colSum += m[i][j];

            if (m[i][j] < colMin) colMin = m[i][j];
            if (m[i][j] > colMax) colMax = m[i][j];
        }

        cout << "Column " << j + 1
            << ": sum = " << colSum
            << ", min = " << colMin
            << ", max = " << colMax
            << ", average = " << colSum / N
            << endl;
    }

    return 0;
}