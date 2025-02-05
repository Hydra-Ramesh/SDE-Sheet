#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Function to check if a substring is a palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    // Helper function for backtracking
    void helper(int idx, const string& s, vector<string>& path, vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(s, idx, i)) {  // Check if the substring is a palindrome
                path.push_back(s.substr(idx, i - idx + 1));  // Take the substring
                helper(i + 1, s, path, ans);  // Recur for remaining substring
                path.pop_back();  // Backtrack
            }
        }
    }

    // Main function to find all palindrome partitions
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        helper(0, s, path, ans);
        return ans;
    }
};

// Main function to test the optimized solution
int main() {
    Solution sol;
    string s = "aab";

    vector<vector<string>> result = sol.partition(s);

    // Print all palindrome partitions
    cout << "Palindrome Partitions:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (const string& str : subset) {
            cout << "\"" << str << "\" ";
        }
        cout << "]\n";
    }

    return 0;
}
