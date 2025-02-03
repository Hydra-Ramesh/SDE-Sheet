#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0, mid = 0, hi = nums.size() - 1;
        while (mid <= hi) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[lo]);
                lo++;
                mid++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[hi]);
                hi--;
            } else {
                mid++;
            }
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0}; // Example input
    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted Colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
