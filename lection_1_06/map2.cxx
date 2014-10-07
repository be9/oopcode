#include <iostream>
#include <map>

using namespace std;

void f(const map<int, int> &m) {
    cout << m[0] << endl;
}

int main() {
    map<int, int> values = { { 1, 2 }, { 3, 4 }, { 0, 100 } };

    for (auto it = values.begin(); it != values.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "Lowest key: "  << values.begin()->first << endl;
    cout << "Highest key: " << values.rbegin()->first << endl;

    f(values);

    return 0;
}
