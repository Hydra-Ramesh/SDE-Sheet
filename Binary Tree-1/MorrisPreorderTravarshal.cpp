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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left != NULL) {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {  // First visit: create thread and visit node
                    ans.push_back(curr->val); // Visit node (Preorder: Root first)
                    pred->right = curr;  // Create thread
                    curr = curr->left;   // Move left
                } else {  // Second visit: Restore tree and move right
                    pred->right = NULL;  // Remove thread
                    curr = curr->right;  // Move right
                }
            } else {  // No left subtree, visit and move right
                ans.push_back(curr->val);  // Visit node
                curr = curr->right;        // Move right
            }
        }
        return ans;
    }
};

// Helper function to create a sample binary tree
TreeNode* createSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

// Main function to test Morris Preorder Traversal
int main() {
    TreeNode* root = createSampleTree();

    Solution solution;
    vector<int> result = solution.preorderTraversal(root);

    cout << "Preorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
