#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string inputFile;
    string outputFile;
    string key;

    cout << "Input file: ";
    cin >> inputFile;

    cout << "Output file: ";
    cin >> outputFile;

    cout << "Key: ";
    cin >> key;

    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in || !out)
    {
        cout << "File error" << endl;
        return 1;
    }

    char ch;
    int pos = 0;

    while (in.get(ch))
    {
        ch ^= key[pos];

        out.put(ch);

        pos++;

        if (pos >= key.length())
            pos = 0;
    }

    in.close();
    out.close();

    cout << "Done." << endl;

    return 0;
}