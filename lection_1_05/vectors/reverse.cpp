#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> a = { 1, 2, 3, 4 };

    for (auto it = a.rbegin(); it != a.rend(); ++it)
        cout << *it << ' ';     // 4 3 2 1

    cout << endl;
    return 0;
}
