#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    char fileName[100];

    cout << "Enter file name: ";
    cin >> fileName;

    ifstream file(fileName);

    if (!file)
    {
        cout << "Cannot open file!" << endl;

        system("pause");
        return 1;
    }

    char ch;

    int emptyCount = 0;
    int nonEmptyCount = 0;

    cout << "\nFile content:\n\n";

    while (file.get(ch))
    {
        cout << ch;

        if (isspace((unsigned char)ch))
            emptyCount++;
        else
            nonEmptyCount++;
    }

    file.close();

    cout << "\n\nEmpty symbols: " << emptyCount << endl;
    cout << "Non-empty symbols: " << nonEmptyCount << endl;

    system("pause");
    return 0;
}