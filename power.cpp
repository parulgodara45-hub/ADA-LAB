#include <iostream>
using namespace std;

int powerRec(int x, int n) {
    if (n == 0)
        return 1;

    int half = powerRec(x, n / 2);

    if (n % 2 == 0)
        return half * half;
    else
        return half * half * x;
}

int powerRec2(int x, int n) {
    if (n == 0)
        return 1;

    return x * powerRec2(x, n - 1);
}

int main() {
    int x = 2, n = 5;

    cout << powerRec(x, n) << endl;
    cout << powerRec2(x, n) << endl;

    return 0;
}