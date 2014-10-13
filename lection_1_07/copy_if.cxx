#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

inline bool isEven(int x) { return x % 2 == 0; }

int main() {
    vector<int> x = { 1, 2, 3, 4 }, y;
    copy_if(x.begin(), x.end(), back_inserter(y), isEven);

    for (auto val: y)
        cout << val << endl;        // 2… 4

    return 0;
}
