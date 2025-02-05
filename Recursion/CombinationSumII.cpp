#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void findCombination(int idx, int target, vector<int>& ds, vector<vector<int>>& ans, vector<int>& candidates) {
        if (target == 0) {  // If we reach the target sum, store the combination
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1]) continue;

            // If current number is greater than target, no need to proceed further
            if (candidates[i] > target) break;

            ds.push_back(candidates[i]);  // Pick current element
            findCombination(i + 1, target - candidates[i], ds, ans, candidates);  // Move to next index
            ds.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        findCombination(0, target, ds, ans, candidates);
        return ans;
    }
};

// Main function to test the corrected solution
int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Print all unique combinations
    cout << "Combination Sum II Results:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
