#include <iostream>
#include <vector>
using namespace std;

void sumOfSubsets(vector<int>& arr, int n, int target,
                  vector<int>& subset, int idx, int sum,
                  vector<vector<int>>& solutions) {
    if (sum == target) {
        solutions.push_back(subset);
        return;
    }

    if (idx == n || sum > target)
        return;

    subset.push_back(arr[idx]);
    sumOfSubsets(arr, n, target, subset, idx + 1, sum + arr[idx], solutions);
    subset.pop_back();

    sumOfSubsets(arr, n, target, subset, idx + 1, sum, solutions);
}

vector<vector<int>> findSubsetSum(vector<int> arr, int target) {
    vector<vector<int>> solutions;
    vector<int> subset;

    sumOfSubsets(arr, arr.size(), target, subset, 0, 0, solutions);

    cout << "Subsets summing to " << target << ":\n";

    for (const auto& sol : solutions) {
        cout << "[ ";
        for (int x : sol)
            cout << x << " ";
        cout << "]\n";
    }

    return solutions;
}

vector<vector<int>> findSubsetSumIter(vector<int>& arr, int target) {
    vector<vector<int>> solutions;
    int n = arr.size();

    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        vector<int> subset;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subset.push_back(arr[i]);
                sum += arr[i];
            }
        }

        if (sum == target)
            solutions.push_back(subset);
    }

    return solutions;
}

int main() {
    vector<int> arr = {2, 4, 6, 8};
    int target = 10;

    findSubsetSum(arr, target);

    vector<vector<int>> result = findSubsetSumIter(arr, target);

    for (const auto& sol : result) {
        cout << "[ ";
        for (int x : sol)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}