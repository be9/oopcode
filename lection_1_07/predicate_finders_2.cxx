#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    string w("Dolly"), e("  \t\t \n   "), s("Hello Dolly!");

    if (all_of(w.begin(), w.end(), ::isalnum))
        cout << w << " is alphanumeric" << endl;

    if (all_of(e.begin(), e.end(), ::isspace))
        cout << "e is completely whitespace" << endl;

    cout << "Space in " << s << ": " <<
         count_if(s.begin(), s.end(), ::isspace) << endl;

    return 0;
}
