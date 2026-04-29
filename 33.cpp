#include <iostream>
#include <vector>
using namespace std;

bool isSafeHam(int v, vector<vector<int>>& graph, vector<int>& path, int pos) {
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    bool found = false;

    for (int neighbor : graph[path[pos - 1]]) {
        if (neighbor == v) {
            found = true;
            break;
        }
    }

    return found;
}

bool hamiltonianUtil(vector<vector<int>>& graph, vector<int>& path, int pos, int V) {
    if (pos == V) {
        for (int neighbor : graph[path[pos - 1]]) {
            if (neighbor == path[0])
                return true;
        }
        return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafeHam(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianUtil(graph, path, pos + 1, V))
                return true;

            path[pos] = -1;
        }
    }

    return false;
}

bool hamiltonianCycle(vector<vector<int>>& graph, int V) {
    vector<int> path(V, -1);

    path[0] = 0;

    if (hamiltonianUtil(graph, path, 1, V)) {
        cout << "Hamiltonian cycle: ";
        for (int v : path)
            cout << v << " ";
        cout << "0\n";
        return true;
    }

    return false;
}

int main() {
    int V = 5;

    vector<vector<int>> graph = {
        {1, 3},
        {0, 2, 3, 4},
        {1, 4},
        {0, 1, 4},
        {1, 2, 3}
    };

    hamiltonianCycle(graph, V);

    return 0;
}