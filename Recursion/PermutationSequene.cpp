#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> ans;

        // Initialize the list of numbers [1, 2, ..., n]
        for(int i = 1; i < n; i++) {
            fact = fact * i;
            ans.push_back(i);
        }
        ans.push_back(n);  // Add the last number n

        string s = "";
        k = k - 1;  // Convert k to 0-based index

        while(true) {
            s = s + to_string(ans[k / fact]);  // Add the number at the current index
            ans.erase(ans.begin() + k / fact);  // Remove the number from the list

            if(ans.size() == 0) {
                break;
            }

            k = k % fact;  // Update k for the next set of numbers
            fact = fact / ans.size();  // Reduce the factorial for the remaining set
        }

        return s;
    }
};

// Main function to test the solution
int main() {
    Solution sol;

    int n = 3, k = 3;
    cout << "The " << k << "-th permutation of " << n << " numbers is: " << sol.getPermutation(n, k) << endl;

    n = 4; k = 9;
    cout << "The " << k << "-th permutation of " << n << " numbers is: " << sol.getPermutation(n, k) << endl;

    return 0;
}
