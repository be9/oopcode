#include <memory>
#include <iostream>

using namespace std;

class Valuable {
    int value;
public:
    Valuable(int val) : value(val) {
        cout << "Getting value " << value << endl;
    }
    ~Valuable() { cout << "Losing value " << value << endl; }
};

int main() {
    unique_ptr<Valuable> v1(new Valuable(10)), v2;

    cout << v1.get() << ", " << v2.get() << endl;

    v1 = unique_ptr<Valuable>(new Valuable(100));
    v1.swap(v2);

    cout << v1.get() << ", " << v2.get() << endl;

    return 0;
}
