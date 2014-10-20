#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class ParserClient {
public:
    virtual void start() {}
    virtual void processRow(vector<int> &row) {}
    virtual void finish() {}
};

class Parser {
public:
    Parser(istream &_is) : is(_is) {}

    void parse(ParserClient &client) {
        client.start();
        string line;

        while (getline(is, line)) {
            istringstream iss(line);
            vector<int> line_numbers;
            int n = 0;

            while (iss >> n)
                line_numbers.push_back(n);

            if (line_numbers.size() > 0)
                client.processRow(line_numbers);
        }

        client.finish();
    }

private:
    istream &is;
};

int getMedian(vector<int> &numbers) {
    sort(numbers.begin(), numbers.end());
    return numbers[numbers.size() / 2];
}

class MediansMedian : public ParserClient {
public:
    virtual void processRow(vector<int> &row) {
        medians.push_back(getMedian(row));
    }

    bool isEnough() const { return medians.size() > 2; }

    int result() { return getMedian(medians); }

private:
    vector<int> medians;
};

int main(int argc, char **argv) {
    if (argc != 2)
        return 1;

    ifstream ifs(argv[1]);
    if (!ifs)
        return 2;

    MediansMedian medmed;
    Parser p(ifs);
    p.parse(medmed);

    if (medmed.isEnough())
        cout << "Median of medians = " << medmed.result() << endl;
    else
        cout << "Not enough lines" << endl;

    return 0;
}
