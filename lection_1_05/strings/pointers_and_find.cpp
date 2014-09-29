#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main() {
    string s("abcdab");

    puts(s.c_str());        // const char* c_str() const;

    char sum = 0;
    const char *p0 = s.data();
    for (const char *p = p0; p < p0 + s.size(); ++p)
        sum += *p;

    cout << "Sum = " << int(sum) << endl;

    int pos = s.find("ab");
    cout << pos << endl;        // 0

    int rpos = s.rfind("ab");
    cout << rpos << endl;       // 4

    int what = s.find("wat");
    if (what == string::npos)
        cout << "not found" << endl;

    return 0;
}
