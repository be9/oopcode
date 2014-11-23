#include <iostream>
#include <fstream>
#include <string>
#include "chain.h"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 3) {
        cerr << "Usage: markovka <text-file> <number-of-words>" << endl;
        return 1;
    }

    ifstream ifs(argv[1]);
    MarkovChain mc(ifs);

    mc.generate(cout, stoi(argv[2]));

    return 0;
}
