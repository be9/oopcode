#include <string>
#include <algorithm>
#include <iostream>
#include <random>

using namespace std;

int randomLength() {
    static default_random_engine generator;
    static uniform_int_distribution<int> distribution(1, 10);

    return 1 + 2*distribution(generator);
}

string makeSpaceship(int len) {
    if (len < 3)
        return string();

    string ss(len, '<');
    auto it = ss.begin() + len / 2;

    *it++ = '*';
    fill(it, ss.end(), '>');

    return ss;
}

int main() {
    vector<int> lengths(10);
    vector<string> spaceships;

    generate(lengths.begin(), lengths.end(), randomLength);
    transform(lengths.begin(), lengths.end(), back_inserter(spaceships),
              makeSpaceship);

    for (const auto &s: spaceships)
        cout << s << endl;

    return 0;
}
