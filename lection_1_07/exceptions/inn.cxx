#include <iostream>
#include <string>
#include <cctype>
#include <exception>

using namespace std;

class INNException         : public std::exception {};
class WrongLengthException   : public INNException {};
class WrongCharsException    : public INNException {};
class WrongChecksumException : public INNException {};

unsigned long long int parseINN(const string &s) {
    if (s.length() != 10)
        throw WrongLengthException();

    if (!all_of(s.begin(), s.end(), ::isdigit))
        throw WrongCharsException();

    static int coeffs[] = { 2, 4, 10, 3, 5, 9, 4, 6, 8 };

    int res = 0;
    for (int i = 0; i < 9; ++i)
        res += (int(s[i]) - int('0')) * coeffs[i];

    if (int(s[9]) - int('0') != (res % 11) % 10)
        throw WrongChecksumException();

    return stoull(s);
}

int main() {
    string s;
    if (getline(cin, s)) {
        try {
            auto inn = parseINN(s); // например, 5445264092

            cout << "Хороший, годный ИНН: " << inn << endl;
        }
        catch (WrongLengthException &) {
            cerr << "ИНН имеет неверную длину!" << endl;
        }
        catch (WrongCharsException &) {
            cerr << "ИНН содержит недопустимые символы!" << endl;
        }
        catch (WrongChecksumException &) {
            cerr << "У ИНН неверная контрольная сумма!" << endl;
        }
        catch (INNException &) {
            cerr << "ИНН никуда не годится!" << endl;
        }
    }
}
