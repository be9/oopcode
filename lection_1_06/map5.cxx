#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Point {
    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    double x, y;
};

inline ostream &operator<<(ostream &os, const Point &p) {
    return os << "[" << p.x << ", " << p.y << "]";
}

int main() {
    map<string, Point> places;

    places.insert(make_pair("Bottom Left", Point(0, 0)));
    places.insert({ "Top Left", Point(0, 100) });

    // pair<iterator, bool>
    auto res = places.insert({ "Top Left", Point(-1, 100) });

    if (res.second)
        cout << "New element was inserted";
    else
        cout << "Old element was updated";

    cout << " (" << res.first->first << "): " << res.first->second << endl;

    return 0;
}
