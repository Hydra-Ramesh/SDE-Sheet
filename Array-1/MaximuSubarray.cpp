#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n = arr.size();
        int res = arr[0];
        int maxEnding = arr[0];
        for (int i = 1; i < n; i++) {
            maxEnding = max(maxEnding + arr[i], arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
};

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // Example input
    Solution sol;
    int maxSum = sol.maxSubArray(arr);
    cout << "Maximum Subarray Sum: " << maxSum << endl;
    return 0;
}
