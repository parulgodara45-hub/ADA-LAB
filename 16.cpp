#include <iostream>
using namespace std;

int partitionQuick(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low == high)
        return arr[low];

    int pi = partitionQuick(arr, low, high);

    if (k == pi)
        return arr[k];
    else if (k < pi)
        return quickSelect(arr, low, pi - 1, k);
    else
        return quickSelect(arr, pi + 1, high, k);
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << quickSelect(arr, 0, n - 1, k) << endl;

    return 0;
}