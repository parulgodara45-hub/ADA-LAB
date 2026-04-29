#include <iostream>
using namespace std;

struct MinMax {
    int min;
    int max;
};

MinMax minMax(int arr[], int low, int high) {
    MinMax result;

    if (low == high) {
        result.min = result.max = arr[low];
        return result;
    }

    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }

    int mid = low + (high - low) / 2;

    MinMax left = minMax(arr, low, mid);
    MinMax right = minMax(arr, mid + 1, high);

    result.min = min(left.min, right.min);
    result.max = max(left.max, right.max);

    return result;
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);

    MinMax result = minMax(arr, 0, n - 1);

    cout << "Min: " << result.min << endl;
    cout << "Max: " << result.max << endl;

    return 0;
}