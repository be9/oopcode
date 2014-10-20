#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

using namespace std;

class Parser {
public:
    Parser(istream &_is) : is(_is) {}

    vector<int> getNext() {
        string line;

        while (getline(is, line)) {
            istringstream iss(line);
            vector<int> line_numbers;
            int n = 0;

            while (iss >> n)
                line_numbers.push_back(n);

            if (line_numbers.size() > 0)
                return line_numbers;
        }

        return vector<int>();
    }
private:
    istream &is;
};

// продолжение на следующем слайде…

int getMedian(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());
    return numbers[numbers.size() / 2];
}

class MediansMedian {
public:
    MediansMedian(Parser &p) : parser(p) {}

    int result() {
        vector<int> medians, line_numbers;

        while (!(line_numbers = parser.getNext()).empty())
            medians.push_back(getMedian(line_numbers));

        if (medians.size() > 2)
            return getMedian(medians);
        else
            throw NotEnoughException();
    }

    class NotEnoughException : public std::exception {};

private:
    Parser &parser;
};

// продолжение на следующем слайде…

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    ifstream ifs(argv[1]);
    if (!ifs)
        return 2;

    try {
        Parser p(ifs);
        int result = MediansMedian(p).result();

        cout << "Median of medians = " << result << endl;
    }
    catch (MediansMedian::NotEnoughException &) {
        cout << "Not enough lines" << endl;
    }

    return 0;
}

#ifdef XYZ

class BaseParser {
public:
    virtual vector<int> getNext() = 0;
};

class Parser : public BaseParser {
public:
    // ...
};

class MediansMedian {
public:
    MediansMedian(BaseParser &p) : parser(p) {}
    // ...
};

// Альтернативный интерфейс для Parser
class Parser {
public:
    Parser(istream &_is) : is(_is) {}

    // было: vector<int> getNext();
    bool getNext(vector<int> &result) {
        string line;
        while (getline(is, line)) {
            result.clear();

            // ....
        }

        return false;
    }

private:
    istream &is;
};

#endif
