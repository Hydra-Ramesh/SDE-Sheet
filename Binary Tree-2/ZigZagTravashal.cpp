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
    // Function to compute the height of the tree
    int levels(TreeNode* root) {
        if (root == NULL) return 0;
        return 1 + max(levels(root->left), levels(root->right));
    }

    // Function to get all nodes at a specific level in zigzag order
    void nthLevel(TreeNode* root, int curr, int level, vector<int>& v, bool leftToRight) {
        if (root == NULL) return;

        if (curr == level) {
            v.push_back(root->val);
            return;
        }

        // Alternate between left-to-right and right-to-left traversal
        if (!leftToRight) {
            nthLevel(root->right, curr + 1, level, v, leftToRight);
            nthLevel(root->left, curr + 1, level, v, leftToRight);
        } else {
            nthLevel(root->left, curr + 1, level, v, leftToRight);
            nthLevel(root->right, curr + 1, level, v, leftToRight);
        }
    }

    // Function to traverse each level and collect nodes in zigzag order
    void orderTraversal(TreeNode* root, vector<vector<int>>& ans) {
        int n = levels(root);
        bool leftToRight = true;

        for (int i = 1; i <= n; i++) {
            vector<int> v;
            nthLevel(root, 1, i, v, leftToRight);
            ans.push_back(v);
            leftToRight = !leftToRight; // Toggle direction
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        orderTraversal(root, ans);
        return ans;
    }
};

// Function to print the zigzag level order traversal result
void printZigzagOrder(const vector<vector<int>>& levels) {
    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Function to create a sample binary tree
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
    vector<vector<int>> result = sol.zigzagLevelOrder(root);

    cout << "Zigzag Level Order Traversal:\n";
    printZigzagOrder(result);

    return 0;
}
