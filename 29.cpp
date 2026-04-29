#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V) {
    const int INF = 1e9;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == -1 && i != j)
                dist[i][j] = INF;
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    cout << "All-pairs shortest distances:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] >= INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> dist = {
        {0, 3, -1, 7},
        {-1, 0, 1, 8},
        {-1, -1, 0, 2},
        {-1, -1, -1, 0}
    };

    int V = dist.size();

    floydWarshall(dist, V);

    return 0;
}