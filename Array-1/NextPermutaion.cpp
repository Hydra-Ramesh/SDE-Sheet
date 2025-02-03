#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        reverse(nums.begin() + idx + 1, nums.end());
        int j = -1;
        for (int i = idx + 1; i < n; i++) {
            if (nums[i] > nums[idx]) {
                j = i;
                break;
            }
        }
        int temp = nums[idx];
        nums[idx] = nums[j];
        nums[j] = temp;
        return;
    }
};

int main() {
    Solution sol;
    vector<int> nums;

    // Input the vector of integers
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // Output the original permutation
    cout << "Original permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Generate the next permutation
    sol.nextPermutation(nums);

    // Output the next permutation
    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
