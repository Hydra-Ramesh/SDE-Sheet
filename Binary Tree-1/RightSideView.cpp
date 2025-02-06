#include <iostream>
#include <vector>

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
        if(root == NULL) {
            return 0;
        }
        return 1 + max(levels(root->left), levels(root->right));
    }

    void preorder(TreeNode* root, vector<int>& ans, int level) {
        if(root == NULL) return;
        ans[level] = root->val;  // Store the rightmost value at each level
        preorder(root->left, ans, level + 1);  // Visit left subtree
        preorder(root->right, ans, level + 1); // Visit right subtree
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans(levels(root), 0);
        preorder(root, ans, 0);
        return ans;
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    return root;
}

// Main function to test right side view
int main() {
    TreeNode* root = createSampleTree();

    Solution solution;
    vector<int> result = solution.rightSideView(root);

    cout << "Right Side View: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up allocated memory
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
