#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to calculate the height of the tree
    int levels(TreeNode* node) {
        if (node == NULL)
            return 0;
        return 1 + max(levels(node->left), levels(node->right));
    }

    // Function to get all nodes at a specific level
    void nthLevelelement(TreeNode* node, int curr, int level, vector<int>& v) {
        if (node == NULL)
            return;
        if (curr == level) {
            v.push_back(node->val);
            return;
        }
        nthLevelelement(node->left, curr + 1, level, v);
        nthLevelelement(node->right, curr + 1, level, v);
    }

    // Function to perform level-order traversal and store results
    void levelsOrder(TreeNode* node, vector<vector<int>>& ans) {
        int n = levels(node);
        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthLevelelement(node, 1, i, v);
            ans.push_back(v);
        }
    }

    // Main function for level-order traversal
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelsOrder(root, ans);
        return ans;
    }
};

// Function to print level order traversal result
void printLevelOrder(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to create a simple binary tree for testing
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level Order Traversal:\n";
    printLevelOrder(result);

    return 0;
}
