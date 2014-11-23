#include <algorithm>
#include <random>
#include <chrono>
#include <iterator>
#include <assert.h>
#include "chain.h"

using namespace std;

namespace {
    // Добавляет s к префиксу st. Полный размер префикса - p_size.
    void maintainPrefix(vector<string> &p, const string &s, int p_size) {
        if (p.size() < p_size)
            p.push_back(s);
        else {
            // Сдвиг влево на 1
            move(p.begin() + 1, p.end(), p.begin());
            p.back() = s;
        }
    }
}

MarkovChain::MarkovChain(istream &is) {
    vector<string> prefix;
    string s;

    std::map<std::vector<std::string>, std::map<std::string, size_t> >
        all_counts;

    while (is >> s) {
        if (prefix.size() == 2) {
            prefix_counts[prefix]++;
            all_counts[prefix][s]++;
        }

        maintainPrefix(prefix, s, 2);
    }

    for (const auto &pair: all_counts) {
        auto &t = transitions[pair.first];

        for (const auto &pair2: pair.second)
            t.push_back(pair2);
    }
}

void MarkovChain::generate(ostream &os, int nwords)
{
    random_device rd;
    default_random_engine rng(rd());

    if (!prefix_counts.size())
        return;

    int count = 0,
        prefix_no = uniform_int_distribution<int>(0, prefix_counts.size() - 1)(rng);

    auto it = prefix_counts.begin();
    advance(it, prefix_no);

    vector<string> prefix = it->first;

    for (const auto &s : prefix) {
        if (count >= nwords)
            break;

        os << s << ' ';
        count++;
    }

    for (; count < nwords; ++count) {
        const auto &options = transitions.at(prefix);
        size_t total_count = prefix_counts.at(prefix);
        size_t q = uniform_int_distribution<size_t>(0, total_count - 1)(rng);
        size_t accum = 0;
        string next_word;

        for (const auto &option : options) {
            if (q >= accum && q < accum + option.second) {
                next_word = option.first;
                break;
            }

            accum += option.second;
        }

        assert(!next_word.empty());
        os << next_word << ' ';

        maintainPrefix(prefix, next_word, 2);
    }
}
