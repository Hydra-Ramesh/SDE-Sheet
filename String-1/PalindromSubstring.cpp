#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        string longest = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) && (j - i + 1 > longest.length())) {
                    longest = s.substr(i, j - i + 1);
                }
            }
        }
        return longest;
    }
};

int main() {
    Solution sol;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = sol.longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
