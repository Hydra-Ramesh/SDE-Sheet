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
    int levels(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + max(levels(root->left), levels(root->right));
    }

    void preorder(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) return;
        ans[level] = root->val;
        preorder(root->right, ans, level + 1);
        preorder(root->left, ans, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root), 0);
        preorder(root, ans, 0);
        return ans;
    }

    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans(levels(root), 0);
        preorder(root, ans, 0);
        return ans[ans.size() - 1];
    }
};

int main() {
    // Creating a sample tree:
    //           1
    //         /   \
    //        2     3
    //       / \   / \
    //      4   5 6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;

    // Right Side View of the Tree
    vector<int> rightSide = solution.rightSideView(root);
    cout << "Right side view: ";
    for (int val : rightSide) {
        cout << val << " ";
    }
    cout << endl;

    // Find Bottom Left Value
    int bottomLeftValue = solution.findBottomLeftValue(root);
    cout << "Bottom left value: " << bottomLeftValue << endl;

    return 0;
}
