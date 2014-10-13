#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline bool isEven(int x) {
    return x % 2 == 0;
}

template <int N>
inline bool greaterThan(int x) {
    return x > N;
}

int main() {
    vector<int> x = { 1, 2, 3, 4, 5, 6, 7, 8 };
    if (!all_of(x.begin(), x.end(), isEven))
        cout << "Not all are even!" << endl;

    if (any_of(x.begin(), x.end(), isEven))
        cout << "But there is at least one even!" << endl;

    if (none_of(x.begin(), x.end(), greaterThan<10>))
        cout << "No number is > 10!" << endl;

    return 0;
}
