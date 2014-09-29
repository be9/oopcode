#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

string getLine(int n) {
    ostringstream oss;

    oss << n << "^2=" << n * n;
    return oss.str();
}

int main() {
    ofstream of;

    of.open("out.txt", ofstream::out);

    if (!of) {
        cerr << "Cannot open file for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        string line = getLine(i);

        of << line << endl;
    }

    of.close();
}
