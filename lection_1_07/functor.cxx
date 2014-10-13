#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

struct less_than {
    less_than(int _value)
        : value(_value) {}

    bool operator()(int x) const {
        return x < value;
    }

    int value;
};

int main() {
    vector<int> x = { 1, 2, 3, 4 }, y;
    copy_if(x.begin(), x.end(), back_inserter(y), less_than(3));

    for (auto val: y)
        cout << val << endl;        // 1… 2

    return 0;
}
