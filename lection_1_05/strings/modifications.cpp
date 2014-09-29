#include <iostream>
#include <string>

using namespace std;

const std::string A1("a1");

int main() {
    string s("abcd");

    cout << "String size = " << s.size() << endl;

    s.clear();
    if (s.empty())
        cout << "s is empty now!" << endl;

    s += "1234";
    cout << s[3] << endl;           // 4

    s.insert(1, "abc");             // 1abc234
    s.erase(2, 2);                  // 1a234
    s.replace(0, 2, A1);            // a1234

    cout << s.substr(2)    << endl;    // 234
    cout << s.substr(2, 1) << endl;    // 2

    return 0;
}
