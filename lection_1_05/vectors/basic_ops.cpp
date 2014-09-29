#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;                   // 10… 20… 30

    vector<int> zeroes(100), fives(10, 5);
    v = zeroes;

    cout << v.size() << ' ' << v.front() << endl;           // 100 0
    cout << fives.size() << ' ' << fives.back() << endl;    // 10 5

    return 0;
}
