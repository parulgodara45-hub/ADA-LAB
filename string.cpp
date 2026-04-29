#include <iostream>
#include <string>
using namespace std;

void permute(string &s, int index) {
    if (index == (int)s.length()) {
        cout << s << "\n";
        return;
    }

    for (int i = index; i < (int)s.length(); ++i) {
        swap(s[index], s[i]);
        permute(s, index + 1);
        swap(s[index], s[i]);
    }
}

int main() {
    string s = "ABC";
    permute(s, 0);
    return 0;
}