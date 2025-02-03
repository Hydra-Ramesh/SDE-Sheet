#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int m = numRows;
        vector<vector<int>> v;
        for (int i = 0; i < m; i++) {
            vector<int> a(i + 1);
            v.push_back(a);
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    v[i][j] = 1;
                } else {
                    v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
                }
            }
        }
        return v;
    }
};

int main() {
    Solution sol;
    int numRows;

    // Input the number of rows for Pascal's Triangle
    cout << "Enter the number of rows: ";
    cin >> numRows;

    // Generate Pascal's Triangle
    vector<vector<int>> triangle = sol.generate(numRows);

    // Print Pascal's Triangle
    cout << "Pascal's Triangle with " << numRows << " rows:" << endl;
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
