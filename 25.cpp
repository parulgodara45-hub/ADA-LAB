#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findMinCostPath(vector<vector<int>>& cost, int n) {
    vector<int> minCost(n, INT_MAX);
    vector<int> decision(n, -1);

    minCost[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != -1 && cost[i][j] + minCost[j] < minCost[i]) {
                minCost[i] = cost[i][j] + minCost[j];
                decision[i] = j;
            }
        }
    }

    cout << "Minimum cost: " << minCost[0] << "\n";

    int curr = 0;
    cout << "Path: " << curr;

    while (decision[curr] != -1) {
        curr = decision[curr];
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

    findMinCostPath(cost, n);

    return 0;
}