#include <iostream>
using namespace std;

int findNumber(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] == arr[j])
                return arr[i];
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << findNumber(arr, n) << endl;

    return 0;
}