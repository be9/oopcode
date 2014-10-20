#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> readNumbers(istream &is) {
    string line;
    vector<vector<int>> result;

    while (getline(is, line)) {
        istringstream iss(line);
        vector<int> line_numbers;
        int n = 0;

        while (iss >> n)
            line_numbers.push_back(n);

        if (line_numbers.size() > 0)
            result.push_back(line_numbers);
    }

    return result;
}

int getMedian(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());

    return numbers[numbers.size() / 2];
}

// продолжение на следующем слайде…

int medianOfMedians(vector<vector<int>> &vec) {
    vector<int> medians;

    transform(vec.begin(), vec.end(), back_inserter(medians), getMedian);

    return getMedian(medians);
}

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    ifstream ifs(argv[1]);
    if (!ifs)
        return 2;

    auto numbers = readNumbers(ifs);

    if (numbers.size() > 2)
        cout << "Median of medians = " << medianOfMedians(numbers) << endl;
    else
        cout << "Not enough lines" << endl;

    return 0;
}
