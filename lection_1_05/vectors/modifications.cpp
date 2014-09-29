#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = { 1, 2, 3, 4 };

    a.resize(5);        // 1 2 3 4 5 0
    a.resize(7, 99);    // 1 2 3 4 5 0 99 99
    a.resize(3);        // 1 2 3
    a.pop_back();       // 1 2

    a.insert(a.begin() + 1, 7);   // 1 7 2

    vector<int> b = { -1, -2 };

    a.insert(a.begin(), b.begin(), b.end());  // -1 -2 1 7 2
    //        куда       откуда    докуда

    a.insert(a.end(), b.rbegin(), b.rend());  // -1 -2 1 7 2 -2 -1

    a.erase(a.begin() + 2);                   // -1 -2 7 2 -2 -1
    a.erase(a.begin() + 3, a.end());          // -1 -2 7

    a.swap(b);  // a <==> b
    a.clear();  // очистка массива

    for (int x: a)
        cout << x << endl;

    return 0;
}
