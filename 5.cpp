#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int target, int index) {
    if (index >= n)
        return false;

    if (arr[index] == target)
        return true;

    return linearSearch(arr, n, target, index + 1);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    if (linearSearch(arr, n, target, 0))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}