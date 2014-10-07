#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l1 = { 1, 2, 3, 4 }, l2 = { 10, 20, 30 };

    auto it = l1.begin();
    ++it;       // указывает на «2»

    // Переносим элементы l2 в список l1
    l1.splice(it, l2);
    // l1: { 1, 10, 20, 30, 2, 3, 4}
    // l2: пуст

    l2.splice(l2.begin(), l1, it);
    // l1: { 1, 10, 20, 30, 3, 4}
    // l2: { 2 }, it недействителен

    it = l1.begin();
    advance(it, 3); // указывает теперь на «30»
    l1.splice(l1.begin(), l1, it, l1.end());
    // l1: { 30, 3, 4, 1, 10, 20 }

    for (auto x: l1) cout << x << endl;
    for (auto x: l2) cout << x << endl;
    return 0;
}
