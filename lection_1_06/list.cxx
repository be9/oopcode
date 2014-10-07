#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
    vector<int> v = { 1, 2, 3, 4 };
    list<int> l;

    copy(v.begin(), v.end(), front_inserter(l));

    for (auto x: l)
        cout << x << endl;  // 4… 3… 2… 1

    return 0;
}
