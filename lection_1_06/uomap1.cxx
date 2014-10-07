#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> population;

    population["Russia"] = 143800000;
    population["France"] = 66616416;
    population["Nauru"]  = 9378;

    string country;
    if (getline(cin, country)) {
        auto it = population.find(country);

        if (it == population.end())
            cout << "No data for country '" << country << "' found.\n" <<
                    "Meanwhile, Nauru population is " <<
                    population["Nauru"] << endl;
        else
            cout << it->first << " population is " << it->second << endl;
    }

    return 0;
}
