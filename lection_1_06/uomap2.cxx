#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct Date {
    int y, m, d;

    Date(int _y = 0, int _m = 0, int _d = 0) :
        y(_y), m(_m), d(_d) {}
};

inline bool operator==(const Date &d1, const Date &d2) {
    return d1.y == d2.y && d1.m == d2.m && d1.d == d2.d;
}

template<>
struct hash<Date> {
    size_t operator()(const Date &d) const {
        return (d.y << 10) | (d.m << 5) | d.d;
    }
};

inline ostream &operator<<(ostream &os, const Date &date) {
    return os << date.y << '-' << date.m << '-' << date.d;
}

unordered_map<Date, string> birthdays;

int main() {
    birthdays.insert({ Date(1980, 7, 15), "Oleg" });
    birthdays.insert({ Date(1914, 10, 6), "Thor Heyerdahl" });
    birthdays.insert({ Date(1830, 8, 18), "Franz Joseph I." });

    for (const auto &p: birthdays)
        cout << p.first << ": " << p.second << endl;

    return 0;
}
