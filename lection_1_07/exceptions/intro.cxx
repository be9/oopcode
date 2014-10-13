#include <iostream>

class A {
public:
    ~A() { std::cout << "~A()" << std::endl; }
};

class B {
public:
    ~B() { std::cout << "~B()" << std::endl; }
};

void cc() {
    throw 123;
}

void bb() {
    B b;
    cc();
}

void aa() {
    A a;
    bb();
}

int main() {
    try {
        aa();
    }
    catch (int v) {
        std::cout << "Caught " << v << std::endl;
    }
}
