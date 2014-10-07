#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> first  = { 1, 2, 3 };
    std::forward_list<int> second = { 10, 20, 30 };

    auto it = first.begin();  // указывает на «1»

    first.splice_after(first.before_begin(), second);
                        // first: 10 20 30 1 2 3
                        // second: пуст
                        // "it" всё ещё указывает на «1»

    second.splice_after(second.before_begin(), first, first.begin(), it);
                        // first: 10 1 2 3
                        // second: 20 30

    first.splice_after(first.before_begin(), second, second.begin());
                        // first: 30 10 1 2 3
                        // second: 20

    std::cout << "first:";
    for (int x: first) std::cout << " " << x;
    std::cout << std::endl;

    std::cout << "second:";
    for (int x: second) std::cout << " " << x;
    std::cout << std::endl;

    return 0;
}
