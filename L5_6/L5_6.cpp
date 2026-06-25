#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        cout << "Usage: encrypt input output key" << endl;
        return 1;
    }

    ifstream in(argv[1], ios::binary);
    ofstream out(argv[2], ios::binary);

    if (!in || !out)
    {
        cout << "File error" << endl;
        return 1;
    }

    char* key = argv[3];

    int keyPos = 0;
    int keyLen = strlen(key);

    char ch;

    while (in.get(ch))
    {
        ch ^= key[keyPos];

        out.put(ch);

        keyPos++;

        if (keyPos >= keyLen)
            keyPos = 0;
    }

    return 0;
}