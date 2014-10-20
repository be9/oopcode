#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

class Medianer {
public:
    Medianer(const char *filename)
            : ifs(filename) {
        if (!ifs)
            throw FileErrorException();
    }

    int getMedian();

    class Exception : public std::exception {};
    class FileErrorException : public Exception {};
    class NotEnoughException : public Exception {};

private:
    ifstream ifs;

    int calcMedian(vector<int> &numbers);
};

// продолжение на следующем слайде…

int Medianer::calcMedian(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());

    return numbers[numbers.size() / 2];
}

int Medianer::getMedian() {
    vector<int> medians;
    string line;

    while (getline(ifs, line)) {
        istringstream iss(line);
        vector<int> numbers;
        int n = 0;

        while (iss >> n)
            numbers.push_back(n);

        if (numbers.size() > 0)
            medians.push_back(calcMedian(numbers));
    }

    if (medians.size() > 2)
        return calcMedian(medians);
    else
        throw NotEnoughException();
}

// продолжение на следующем слайде…

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    try {
        Medianer m(argv[1]);
        int med = m.getMedian();

        cout << "Median of medians = " << med << endl;
    }
    catch (Medianer::FileErrorException &) {
        return 2;
    }
    catch (Medianer::NotEnoughException &) {
        cout << "Not enough lines" << endl;
    }

    return 0;
}
