#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isSafeQueens(vector<int>& positions, int row, int col) {
    for (int i = 0; i < row; i++) {
        int prevCol = positions[i];

        if (prevCol == col || abs(i - row) == abs(prevCol - col))
            return false;
    }

    return true;
}

void solveNQueensUtil(int n, vector<int>& positions, int row, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(positions);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafeQueens(positions, row, col)) {
            positions[row] = col;
            solveNQueensUtil(n, positions, row + 1, solutions);
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<int> positions(n, -1);
    vector<vector<int>> solutions;

    solveNQueensUtil(n, positions, 0, solutions);

    cout << "Found " << solutions.size() << " solutions for " << n << "-Queens\n";

    for (const auto& sol : solutions) {
        for (int col : sol)
            cout << col << " ";
        cout << "\n";
    }

    return solutions;
}

int main() {
    int n = 4;

    solveNQueens(n);

    return 0;
}