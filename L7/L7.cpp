#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Абстрактный базовый класс фигуры
class Figure
{
protected:
    int x, y;      // координаты фигуры
    int color;     // цвет фигуры

public:
    Figure(int x, int y, int color)
    {
        this->x = x;
        this->y = y;
        this->color = color;
    }

    // Виртуальный деструктор
    virtual ~Figure() {}

    // Чисто виртуальные методы
    virtual void show() = 0;
    virtual void hide() = 0;

    // Метод перемещения фигуры
    virtual void fly(int step)
    {
        while (!_kbhit())
        {
            hide();

            x += rand() % (step + 1) - step / 2;
            y += rand() % (step + 1) - step / 2;

            if (x < 1) x = 1;
            if (x > 70) x = 70;
            if (y < 1) y = 1;
            if (y > 20) y = 20;

            show();

            Sleep(300);
        }

        _getch();
    }

    // Установка позиции курсора
    void setCursor(int x, int y)
    {
        COORD pos;
        pos.X = x;
        pos.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    }

    // Установка цвета текста
    void setColor(int color)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
};

// Класс круга
class Circle : public Figure
{
protected:
    int radius;

public:
    Circle(int x, int y, int radius, int color)
        : Figure(x, y, color)
    {
        this->radius = radius;
    }

    // Вывод круга
    void show() override
    {
        setColor(color);
        setCursor(x, y);
        cout << "O";
    }

    // Скрытие круга
    void hide() override
    {
        setCursor(x, y);
        cout << " ";
    }
};

// Класс кольца, наследуется от круга
class Ring : public Circle
{
private:
    int width;

public:
    Ring(int x, int y, int radius, int color, int width)
        : Circle(x, y, radius, color)
    {
        this->width = width;
    }

    // Вывод кольца
    void show() override
    {
        setColor(color);
        setCursor(x, y);
        cout << "@";
    }

    // Сужение кольца
    void narrow()
    {
        if (width > 1)
            width--;
    }

    // Расширение кольца
    void expand()
    {
        width++;
    }

    // Перемещение со сменой цвета и размера
    void fly(int step) override
    {
        while (!_kbhit())
        {
            hide();

            x += rand() % (step + 1) - step / 2;
            y += rand() % (step + 1) - step / 2;

            if (x < 1) x = 1;
            if (x > 70) x = 70;
            if (y < 1) y = 1;
            if (y > 20) y = 20;

            color = rand() % 15 + 1;

            if (rand() % 2 == 0)
                narrow();
            else
                expand();

            show();

            Sleep(300);
        }

        _getch();
    }
};

int main()
{
    srand(time(0));

    cout << "Laboratory work 7" << endl;
    cout << "Press any key to stop moving object." << endl;
    system("pause");
    system("cls");

    Circle circle(10, 5, 3, 10);
    Ring ring(40, 10, 5, 12, 2);

    cout << "Circle movement. Press any key to stop." << endl;
    circle.fly(6);

    system("cls");

    cout << "Ring movement with color and size changing. Press any key to stop." << endl;
    ring.fly(6);

    system("cls");

    cout << "Program finished." << endl;

    system("pause");

    return 0;
}