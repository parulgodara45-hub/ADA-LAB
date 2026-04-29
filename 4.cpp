#include <iostream>
#include <string>
using namespace std;

void generate(string s, int n) {
    if ((int)s.length() == n) {
        cout << s << "\n";
        return;
    }

    s.push_back('0');
    generate(s, n);
    s.pop_back();

    s.push_back('1');
    generate(s, n);
    s.pop_back();
}

int main() {
    int n = 3;
    generate("", n);
    return 0;
}