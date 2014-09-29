#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = { 1, 2, 3, 4 };

    for (vector<int>::const_iterator it = a.begin(); it != a.end(); ++it)
        cout << *it << ' ';

    vector<int> a = { 1, 2, 3, 4 };

    for (auto it = a.cbegin(); it != a.cend(); ++it)
        cout << *it << ' ';     // 1 2 3 4

    for (auto &x: a)
        ++x;

    for (auto x: a)
        cout << x << ' ';       // 2 3 4 5

    return 0;
}
