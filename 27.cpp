#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void backwardDP(vector<vector<int>>& cost, int n) {
    vector<int> minCost(n, INT_MAX);
    vector<int> nextVertex(n, -1);

    minCost[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != -1 && minCost[j] != INT_MAX) {
                if (cost[i][j] + minCost[j] < minCost[i]) {
                    minCost[i] = cost[i][j] + minCost[j];
                    nextVertex[i] = j;
                }
            }
        }
    }

    cout << "Minimum cost: " << minCost[0] << "\n";
    cout << "Path: " << 0;

    int curr = 0;

    while (nextVertex[curr] != -1) {
        curr = nextVertex[curr];
        cout << " -> " << curr;
    }

    cout << "\n";
}

int main() {
    vector<vector<int>> cost = {
        { -1, 1, 2, 5, -1 },
        { -1, -1, 4, 2, 7 },
        { -1, -1, -1, 3, 4 },
        { -1, -1, -1, -1, 2 },
        { -1, -1, -1, -1, -1 }
    };

    int n = cost.size();

    backwardDP(cost, n);

    return 0;
}