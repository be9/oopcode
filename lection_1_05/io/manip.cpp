#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double f = 3.1415926, k = 150;

    cout << setw(10) << k << endl;          //        150
    cout << setprecision(3) << f << endl;   // 3.14
    cout << setprecision(5) << f << endl;   // 3.1416

    cout << setfill('x') << setw(15) << left << 100 << endl;
    // 100xxxxxxxxxxxx

    return 0;
}
