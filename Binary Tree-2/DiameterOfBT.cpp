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
    int maxDia = 0;  // Stores the maximum diameter

    // Optimized DFS function to compute diameter & height in a single pass
    int depth(TreeNode* root) {
        if (root == NULL) return 0;

        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);

        // Update maxDia with the diameter of this node
        maxDia = max(maxDia, leftDepth + rightDepth);

        // Return height of current node
        return max(leftDepth, rightDepth) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);  // Start DFS traversal
        return maxDia;
    }
};

// Function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    TreeNode* root = createSampleTree();

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);

    cout << "Diameter of the Binary Tree: " << diameter << endl;

    return 0;
}
