#include <iostream>
#include "geopoint.h"

using namespace std;

int main()
{
    Geopoint nsk_lenin_square(55.030039, 82.920084, 15),
             msk_red_square(55.753915, 37.620525, 15);

    cout << "Distance (km) = " <<
        nsk_lenin_square.distanceTo(msk_red_square) / 1000 << endl;

    return 0;
}
