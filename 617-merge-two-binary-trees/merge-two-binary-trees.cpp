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
    TreeNode* solve( TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return nullptr;

        int sum = 0;
        if(root1) sum += root1->val;
        if(root2) sum += root2->val;

        TreeNode* root = new TreeNode(sum);

        TreeNode* r1left = (!root1) ? nullptr : root1->left;
        TreeNode* r2left = (!root2) ? nullptr : root2->left;

        TreeNode* r1right = (!root1) ? nullptr : root1->right;
        TreeNode* r2right = (!root2) ? nullptr : root2->right;

        root->left = solve(r1left,r2left);
        root->right = solve(r1right, r2right);

        return root;

    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};