#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

inline int increase(int i) { return i + 1; }

int main() {
    vector<int> x = { 1, 2, 3, 4 }, y;

    transform(x.begin(), x.end(), back_inserter(y), increase);

    for (auto val: y)
        cout << val << endl;        // 2… 3… 4… 5

    // in-place transform
    transform(y.begin(), y.end(), y.begin(), increase);

    for (auto val: y)
        cout << val << endl;        // 3… 4… 5… 6

    // binary op
    transform(x.begin(), x.end(),   // источник 1-го аргумента
              y.begin(),            // источник 2-го аргумента
              y.begin(),            // куда писать результат
              plus<int>());         // операция (функция или функтор)

    for (auto val: y)
        cout << val << endl;        // 4… 6… 8… 10

    return 0;
}
