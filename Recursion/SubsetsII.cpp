#include <iostream>
#include <vector>
#include <algorithm>  // Required for sorting

using namespace std;

class Solution {
public:
    void findSubsets(int idx, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);  // Store the current subset

        for (int i = idx; i < nums.size(); i++) {
            // Skip duplicates
            if (i != idx && nums[i] == nums[i - 1]) continue;

            // Include nums[i] in the subset
            ds.push_back(nums[i]);
            findSubsets(i + 1, nums, ds, ans);

            // Backtrack: Remove last added element
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        ans.reserve(1 << nums.size());   // Pre-allocate memory for efficiency
        findSubsets(0, nums, ds, ans);

        return ans;
    }
};

// Main function to test the optimized code
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};  // Example input
    vector<vector<int>> result = sol.subsetsWithDup(nums);

    // Print all unique subsets
    cout << "Unique Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
