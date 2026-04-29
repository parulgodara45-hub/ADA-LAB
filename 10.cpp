#include <iostream>
#include <vector>
using namespace std;

int findDup(const vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); ++i) {
        if ((nums[i] ^ i) != 0)
            return nums[i];
    }
    return -1;
}

int main() {
    vector<int> nums = {0, 1, 2, 3, 3, 5};

    cout << findDup(nums) << endl;

    return 0;
}