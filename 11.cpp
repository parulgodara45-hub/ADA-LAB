#include <iostream>
using namespace std;

int jumps(double v, int t) {
    if (v < 1)
        return t;

    t++;
    v -= 0.425 * v;

    return jumps(v, t);
}

int jumpsIterative(double v) {
    int count = 0;

    while (v >= 1) {
        count++;
        v *= 0.575;
    }

    return count;
}

int main() {
    double v = 10;

    cout << jumps(v, 0) << endl;
    cout << jumpsIterative(v) << endl;

    return 0;
}