#include <unordered_set>
#include <iostream>

using namespace std;

int main() {
    unordered_set<string> elements;
    string input;

    while (getline(cin, input)) {
        if (input.empty())
            continue;

        switch (input[0]) {
        case '+':
            elements.insert(input.substr(1));
            break;

        case '-':
            elements.erase(input.substr(1));
            break;

        case '.':
            for (const auto &el: elements)
                cout << "> " << el << endl;
            break;

        default:
            cout << "Enter +something, -something, or '.'" << endl;
        }
    }

    return 0;
}
