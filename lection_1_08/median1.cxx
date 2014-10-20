#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getMedian(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());

    return numbers[numbers.size() / 2];
}

// продолжение на следующем слайде…

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    ifstream ifs(argv[1]);
    if (!ifs)
        return 2;

    vector<int> medians;
    string line;

    while (getline(ifs, line)) {
        istringstream iss(line);
        vector<int> numbers;
        int n = 0;

        while (iss >> n)
            numbers.push_back(n);

        if (numbers.size() > 0)
            medians.push_back(getMedian(numbers));
    }

    if (medians.size() > 2)
        cout << "Median of medians = " << getMedian(medians) << endl;
    else
        cout << "Not enough lines" << endl;

    return 0;
}
