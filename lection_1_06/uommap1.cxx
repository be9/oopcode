#include <unordered_map>
#include <iostream>
#include <random>

using namespace std;

default_random_engine generator;
uniform_int_distribution<int> distribution(1, 1000);

int main() {
    unordered_multimap<int, int> values;

    for (int i = 0; i < 10000; ++i)
        values.insert({ distribution(generator), distribution(generator) });

    cout << "Buckets: " << values.bucket_count() << endl;
    cout << "Load factor: " << values.load_factor() << endl;

    size_t bucket = 0;

    while (values.bucket_size(bucket) == 0)
        ++bucket;

    cout << "First non-empty bucket: " << bucket << ", size = "
         << values.bucket_size(bucket) << ". Keys:" << endl;

    for (auto it = values.begin(bucket); it != values.end(bucket); ++it)
        cout << it->first << ' ';

    cout << endl;

    return 0;
}
