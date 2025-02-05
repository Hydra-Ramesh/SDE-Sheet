#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findCombination(int idx, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates) {
        if (target == 0) {  // If the target becomes 0, store the valid combination
            ans.push_back(ds);
            return;
        }
        if (idx == candidates.size() || target < 0) return;  // Base case

        // Include the current element (If it's within target)
        if (candidates[idx] <= target) {
            ds.push_back(candidates[idx]);
            findCombination(idx, target - candidates[idx], ds, ans, candidates);  // Pick again
            ds.pop_back();  // Backtrack
        }

        // Exclude current element and move to next index
        findCombination(idx + 1, target, ds, ans, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        findCombination(0, target, ds, ans, candidates);
        return ans;
    }
};

// Main function to test the optimized code
int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    // Print all unique combinations
    cout << "Combination Sum Results:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
