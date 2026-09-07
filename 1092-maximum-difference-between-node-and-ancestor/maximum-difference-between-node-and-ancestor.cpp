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
    int solve( TreeNode* root, int minval, int maxval){
        if(!root) return 0;
        //this min and max value is send by ancensorter,, thus they are min and max tilll anceslor --- also they are passing root ---- to leave

        int option1 = abs(root->val - minval);
        int option2 = abs(root->val - maxval);
        int rootans = max(option1, option2);

        int newmax = max( root->val, maxval);
        int newmin = min(root->val, minval);

        int leftans = solve(root->left, newmin, newmax);
        int rightans = solve(root->right, newmin, newmax);

        return max({rootans , leftans, rightans});

    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root, root->val, root->val);
    }
};