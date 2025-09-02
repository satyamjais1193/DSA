/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* curr; // pointer to build the new tree

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // attach current node to the right of curr
        root->left = nullptr;
        curr->right = root;
        curr = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(-1); 
        curr = dummy;

        inorder(root);

        return dummy->right; 
    }
};
