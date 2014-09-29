#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

bool crit(int x, int y) { return y < x; }
bool isEven(int x)      { return x % 2 == 0; }

int main() {
    vector<int> a = { 1, 4, 9 };
    a.resize(6);    // 1 4 9 0 0 0

    //    откуда      докуда           куда
    copy(a.begin(), a.begin() + 3, a.begin() + 3);  // 1 4 9 1 4 9

    vector<int> b;
    copy(a.rbegin(), a.rend(), back_inserter(b));   // b: 9 4 1 9 4 1

    sort(a.begin(), a.end());                       // a: 1 1 4 4 9 9
    sort(b.begin(), b.end(), crit);                 // b: 9 9 4 4 1 1

    partition(a.begin(), a.end(), isEven);          // a: 4 4 1 1 9 9
    rotate(a.begin(), a.begin() + 3, a.end());      // a: 1 9 9 4 4 1

    for (int x: a)
        cout << x << endl;

    return 0;
}


// std::cout << "Bye!" << endl;
