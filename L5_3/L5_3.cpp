#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string fileName;
    string searchText;

    cout << "File name: ";
    cin >> fileName;

    cout << "Substring: ";
    cin >> searchText;

    ifstream in(fileName);

    if (!in)
    {
        cout << "Cannot open file" << endl;
        return 1;
    }

    ofstream out("result.txt");

    string line;
    int lineNumber = 1;

    while (getline(in, line))
    {
        if (line.find(searchText) != string::npos)
        {
            out << "Found in line "
                << lineNumber
                << ": "
                << line
                << endl;
        }

        lineNumber++;
    }

    in.close();
    out.close();

    cout << "Result saved to result.txt" << endl;

    return 0;
}