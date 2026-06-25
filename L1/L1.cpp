#include <iostream>
#include <stdio.h>

using namespace std;

#define PR(x) printf("x=%p, *x=%d, &x=%p\n", (void*)x, *x, (void*)&x)

int power(int x, int n)
{
    int p = 1;

    for (int i = 0; i < n; i++)
        p *= x;

    return p;
}

void obmen1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void obmen2(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void obmen3(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    // ЗАДАНИЕ 1
    int x, n;

    cout << "Task 1. Power\n";

    cout << "Enter base: ";
    cin >> x;

    cout << "Enter power: ";
    cin >> n;

    cout << x << "^" << n << " = " << power(x, n) << endl;


    // ЗАДАНИЕ 2
    cout << "\nTask 2. Pointers\n";

    int mas[] = { 100, 200, 300 };
    int* ptr1, * ptr2;

    ptr1 = mas;
    ptr2 = &mas[2];

    PR(ptr1);

    ptr1++;

    PR(ptr1);
    PR(ptr2);

    ++ptr2;

    printf("ptr2 - ptr1 = %td\n", ptr2 - ptr1);

    cout << "\nTask 3. Swap\n";

    int a = 2, b = 5;

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    obmen1(a, b);
    cout << "After obmen1: a = " << a << ", b = " << b << endl;

    obmen2(&a, &b);
    cout << "After obmen2: a = " << a << ", b = " << b << endl;

    obmen3(a, b);
    cout << "After obmen3: a = " << a << ", b = " << b << endl;

    return 0;

}