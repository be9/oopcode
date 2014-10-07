#include <set>
#include <iostream>

const char *names[] = { "Vasya", "Kolya", "Vasya", "Vasya", "Petya" };

using namespace std;

int main() {
    set<string> unique_names;

    for (auto name: names)
        unique_names.insert(name);

    for (auto name: unique_names)
        cout << name << endl;       // Kolya… Petya… Vasya
}
