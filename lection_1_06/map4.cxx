#include <iostream>
#include <fstream>
#include <map>
#include <cctype>

using namespace std;

string next_word(istream &is);

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    ifstream ifs(argv[1]);

    if (!ifs)
        return 2;

    string s;
    map<string, int> counters;

    while (!(s = next_word(ifs)).empty())
        ++counters[s];

    for (auto it = counters.begin(); it != counters.end(); ++it)
        cout << it->first << ": " << it->second << endl;
}

string next_word(istream &is) {
    // пропускаем пробелы
    while (is.good()) {
        char c = is.get();

        if (!is.good())
            break;

        if (!isspace(c)) {
            is.unget();
            break;
        }
    }

    string result;

    if (!is)
        return result;  // пустая строка

    while (is.good()) {
        char c = is.get();

        if (!is.good() || isspace(c))
            break;

        result.push_back(c);
    }

    return result;
}
