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
int sum =0;
    void solve(TreeNode * root, bool isLeft){
        if(root && isLeft && !root->left && !root->right){
            sum += root->val;
        }
        if(!root){
            return;

        }
        solve(root->left, true);
        solve(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root, false);
        return sum;
    }
};