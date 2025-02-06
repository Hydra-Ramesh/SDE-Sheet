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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;

        while (curr != NULL) {
            if (curr->left != NULL) {  // If left child exists, find its inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right != NULL && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == NULL) {  // First visit: create thread
                    pred->right = curr;  // Make a temporary link
                    curr = curr->left;   // Move left
                } else {  // Second visit: restore tree and process node
                    pred->right = NULL;  // Remove the thread
                    ans.push_back(curr->val);  // Process current node
                    curr = curr->right;  // Move right
                }
            } else {  // If no left subtree, visit node and move right
                ans.push_back(curr->val);
                curr = curr->right;
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

// Main function to test inorder traversal
int main() {
    TreeNode* root = createSampleTree();

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    cout << "Inorder Traversal: ";
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
