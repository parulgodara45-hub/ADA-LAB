#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void matrixChainOrder(vector<int>& p) {
    int n = p.size() - 1;

    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];

                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum multiplications: " << m[0][n - 1] << "\n";
}

int main() {
    vector<int> p = {10, 20, 30, 40, 30};

    matrixChainOrder(p);

    return 0;
}