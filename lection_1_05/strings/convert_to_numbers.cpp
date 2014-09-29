#include <iostream>
#include <string>

using namespace std;

// int stoi(const string &str, size_t *idx = 0, int base = 10);
// double stod(const string &str, size_t *idx = 0);

int main() {
    string s;
    s = "41abc";

    cout << stoi(s) << endl;                    // 41
    cout << stoi(s, nullptr, 16) << endl;       // 268988

    size_t next = 0;
    cout << stoi(s, &next) << " and [" << s.substr(next) << "]\n";
    // 41 and [abc]

    // base==0: autodetect
    cout << stoi("0x7f", nullptr, 0) << endl;   // 127

    // Числа с плавающей точкой
    cout << stod("1.1e15")  << endl;             // 1.1e+15

    s = "1100efun";
    cout << stod(s, &next) << endl;     // 1100
    cout << s.substr(next) << endl;     // efun

    return 0;
}
