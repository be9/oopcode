#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inp("test.txt");

    if (!inp) {
        cerr << "File not found!" << endl;
        return 1;
    }

    string s;
    int n_line;

    for (int n = 1; getline(inp, s); ++n) {
        cout << "Line " << n << ": " << s << endl;
    }

    return 0;
}
