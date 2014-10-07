#include <map>
#include <vector>
#include <iostream>

using namespace std;

struct Date {
    int y, m, d;

    Date(int _y = 0, int _m = 0, int _d = 0) :
        y(_y), m(_m), d(_d) {}
};

struct Person {
    string name;
    Date dob;
};

int main() {
    vector<Person> people = {
        { "Egor", { 2013, 9, 13 } },
        { "Oleg", { 1980, 7, 15 } },
        { "Denis", { 1980, 7, 15 } },
        { "Tanya", { 1982, 1, 5 } },
        { "Evgeniy", { 1982, 11, 3 } }
    };

    multimap<int, const Person *> people_by_year;

    for (const Person &p: people)
        people_by_year.insert({ p.dob.y, &p });

    auto born_1982 = people_by_year.equal_range(1982);

    cout << "Born in 1982:" << endl;
    for (auto it = born_1982.first; it != born_1982.second; ++it)
        cout << it->second->name << endl;

    return 0;
}
