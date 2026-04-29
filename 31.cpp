#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int tsp(vector<vector<int>>& dist, int n) {
    const int INF = 1e9;

    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF)
                continue;

            for (int j = 0; j < n; j++) {
                if (mask & (1 << j))
                    continue;

                int new_mask = mask | (1 << j);

                dp[new_mask][j] = min(dp[new_mask][j],
                                      dp[mask][i] + dist[i][j]);
            }
        }
    }

    int all_visited = (1 << n) - 1;
    int ans = INF;

    for (int i = 0; i < n; i++) {
        ans = min(ans, dp[all_visited][i] + dist[i][0]);
    }

    return ans;
}

int greedyTSP(vector<vector<int>>& dist, int n) {
    vector<bool> visited(n, false);

    int cost = 0, current = 0;
    visited[0] = true;

    for (int i = 0; i < n - 1; i++) {
        int next = -1, minDist = INT_MAX;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[current][j] < minDist) {
                minDist = dist[current][j];
                next = j;
            }
        }

        cost += minDist;
        visited[next] = true;
        current = next;
    }

    cost += dist[current][0];

    return cost;
}

int main() {
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = dist.size();

    cout << tsp(dist, n) << endl;
    cout << greedyTSP(dist, n) << endl;

    return 0;
}