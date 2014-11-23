#pragma once

#include <istream>
#include <map>
#include <vector>
#include <string>

class MarkovChain {
public:
    MarkovChain(std::istream &is);

    void generate(std::ostream &os, int nwords);

private:
    // Префикс —> сколько всего раз префикс встречался
    std::map<std::vector<std::string>, size_t> prefix_counts;

    // Префикс -> вектор пар {слово за префиксом, сколько раз встр.}
    std::map<std::vector<std::string>,
             std::vector<std::pair<std::string, size_t> > > transitions;
};
