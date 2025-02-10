#include <iostream>
#include <vector>
#include <algorithm> // For sort()

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Copy elements from nums2 to nums1's empty space
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        // Sort the merged array
        sort(nums1.begin(), nums1.end());
    }
};

// Function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    cout << "Before Merge:\n";
    printArray(nums1);

    Solution sol;
    sol.merge(nums1, m, nums2, n);

    cout << "\nAfter Merge:\n";
    printArray(nums1);

    return 0;
}
