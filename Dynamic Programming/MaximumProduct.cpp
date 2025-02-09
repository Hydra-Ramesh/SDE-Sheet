#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProduct = 1;
        int maxProduct = 1;
        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                swap(maxProduct, minProduct);
            }
            maxProduct = max(maxProduct * nums[i], nums[i]);
            minProduct = min(minProduct * nums[i], nums[i]);
            ans = max(ans, maxProduct);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4}; // Example input
    Solution sol;
    cout << "Maximum Product Subarray: " << sol.maxProduct(nums) << endl;
    return 0;
}
