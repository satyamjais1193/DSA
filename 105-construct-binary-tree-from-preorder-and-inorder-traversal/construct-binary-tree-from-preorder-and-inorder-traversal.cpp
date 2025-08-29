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
    unordered_map<int, int> inorderIndex; // to quickly find root position in inorder
    int preorderIndex = 0;                // track root position in preorder
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // store inorder indices for fast lookup
        for (int i = 0; i < inorder.size(); i++) {
            inorderIndex[inorder[i]] = i;
        }
        return helper(preorder, 0, inorder.size() - 1);
    }
    
    TreeNode* helper(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr; // base case
        
        // current root from preorder
        int rootVal = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        // find root in inorder
        int mid = inorderIndex[rootVal];
        
        // build left and right subtrees
        root->left = helper(preorder, left, mid - 1);
        root->right = helper(preorder, mid + 1, right);
        
        return root;
    }
};
