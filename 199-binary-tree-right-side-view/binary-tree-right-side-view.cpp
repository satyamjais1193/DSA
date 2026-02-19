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
    void solve(TreeNode* root,int level, vector<int>& rightside){
        if(!root) return;

        if(level == rightside.size() ){
            rightside.push_back(root->val);
        }

        solve(root->right, level +1, rightside);
        solve(root->left, level +1, rightside);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightside;

        solve(root, 0, rightside);
        return rightside;
    }
};