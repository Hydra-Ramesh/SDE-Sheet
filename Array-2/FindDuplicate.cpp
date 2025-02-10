#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end()); // Sorting takes O(n log n)

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return nums[i]; // Found duplicate
            }
        }
        return -1; // Should never happen, as problem guarantees a duplicate
    }
};

// Function to test the solution
int main() {
    vector<int> nums = {3, 1, 3, 4, 2};

    Solution sol;
    int duplicate = sol.findDuplicate(nums);

    cout << "Duplicate Number: " << duplicate << endl;
    return 0;
}
