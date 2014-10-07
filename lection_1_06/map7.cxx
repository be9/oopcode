#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Date {
    int y, m, d;

    Date(int _y = 0, int _m = 0, int _d = 0) :
        y(_y), m(_m), d(_d) {}
};

map<Date, string> birthdays;

int main() {

    birthdays.insert({ Date(), "Haha" });

    // SYNTAX ERROR:
    // ......
    //  invalid operands to binary expression ('const Date' and 'const Date')
    //    {return __x < __y;}
    
    return 0;
}
