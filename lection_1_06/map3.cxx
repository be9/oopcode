#include <iostream>
#include <map>

using namespace std;

void f(const map<int, int> &m) {
    // ERROR: operator[] is not const!
    // cout << m[0] << endl;

    cout << m.at(0) << endl;
}

int main() {
    map<int, int> values = { { 1, 2 }, { 3, 4 }, { 0, 100 } };

    f(values);  // 100

    return 0;
}
