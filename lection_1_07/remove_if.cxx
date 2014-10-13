#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

void depunct(string &s) {
    auto new_end =
        remove_if(s.begin(), s.end(), ::ispunct);

    s.erase(new_end, s.end());
}

int main() {
    string s("Hello, World!");
    istringstream is(s);

    while (is.good()) {
        string word;

        is >> word;
        depunct(word);
        cout << "Word: '" << word << "'" << endl;
    }

    return 0;
}
