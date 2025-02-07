#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> ans;
        while (ss >> word) {
            ans.push_back(word);
        }
        string res;
        for (int i = ans.size() - 1; i >= 0; i--) {
            res += ans[i];
            if (i != 0) {
                res += " ";
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a sentence: ";
    getline(cin, s);

    string reversed = solution.reverseWords(s);
    cout << "Reversed words: " << reversed << endl;

    return 0;
}
