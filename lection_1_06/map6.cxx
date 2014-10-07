#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> marks = {
        { "Vasya", 2 },
        { "Kolya", 3 },
        { "Petya", 4 },
        { "Sasha", 5 },
        { "Artem", 2 }
    };

    // Удаляем двоечников
    for (auto it = marks.begin(); it != marks.end(); ) {
        if (it->second < 3)
            it = marks.erase(it);
        else
            ++it;
    }

    for (const auto &p: marks)
        cout << p.first << ": " << p.second << endl;

    return 0;
}
