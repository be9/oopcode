#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);        // <--- "  12  911 358  "

    for (int pos = 0;;) {
        // Ищем следующий непробельный символ
        pos = s.find_first_not_of(" \t", pos);
        if (pos == string::npos)
            break;  // Ничего не найдено

        // Ищем следующий пробельный символ
        int pos1 = s.find_first_of(" \t", pos);
        size_t len = (pos1 == string::npos) ? string::npos : pos1 - pos;

        string word(s.substr(pos, len));
        cout << "word = '" << word << "'\n";

        if (pos1 == string::npos)
            break;

        pos = pos1;
    }

    return 0;
}
