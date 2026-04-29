#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

void forwardDP(vector<vector<int>>& cost, int n) {
    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != -1 && dist[i] != INT_MAX) {
                if (dist[i] + cost[i][j] < dist[j]) {
                    dist[j] = dist[i] + cost[i][j];
                    parent[j] = i;
                }
            }
        }
    }

    cout << "Minimum cost: " << dist[n - 1] << "\n";

    vector<int> path;
    int curr = n - 1;

    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << "Path: ";
    for (int v : path)
        cout << v << " ";

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

    forwardDP(cost, n);

    return 0;
}