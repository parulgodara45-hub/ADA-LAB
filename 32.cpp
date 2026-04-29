#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int vertex, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int neighbor : graph[vertex]) {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}

bool coloringUtil(int V, vector<vector<int>>& graph, vector<int>& color, int numColors, int vertex) {
    if (vertex == V)
        return true;

    for (int c = 1; c <= numColors; c++) {
        if (isSafe(vertex, graph, color, c)) {
            color[vertex] = c;

            if (coloringUtil(V, graph, color, numColors, vertex + 1))
                return true;

            color[vertex] = 0;
        }
    }

    return false;
}

bool graphColoring(int V, vector<vector<int>>& graph, int numColors) {
    vector<int> color(V, 0);

    if (coloringUtil(V, graph, color, numColors, 0)) {
        cout << "Colors assigned: ";
        for (int c : color)
            cout << c << " ";
        cout << "\n";
        return true;
    }

    return false;
}

int main() {
    int V = 4;

    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2},
        {0, 1, 3},
        {0, 2}
    };

    int numColors = 3;

    graphColoring(V, graph, numColors);

    return 0;
}