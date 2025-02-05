#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int> ans, vector<vector<int>>& finalAns, int idx) {
        if (idx == nums.size()) {
            finalAns.push_back(ans);
            return;
        }
        // Exclude nums[idx] and move forward
        helper(nums, ans, finalAns, idx + 1);

        // Include nums[idx] and move forward
        ans.push_back(nums[idx]);
        helper(nums, ans, finalAns, idx + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> finalAns;
        helper(nums, ans, finalAns, 0);
        return finalAns;
    }
};

// Main function to test the code
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};  // Example input
    vector<vector<int>> result = sol.subsets(nums);

    // Print all subsets
    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
