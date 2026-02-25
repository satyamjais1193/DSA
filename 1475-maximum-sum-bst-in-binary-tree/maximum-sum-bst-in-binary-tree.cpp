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
class Info{
    public:
    int maxi;
    int mini; 
    int sum; 
    bool isbst;
};
class Solution {
public:
    int maxSum =INT_MIN;
    Info* solve(TreeNode* root){
        if(!root) {
            Info* lastval = new Info();
            lastval->maxi = INT_MIN;
            lastval->mini = INT_MAX;
            lastval->sum =0;
            lastval->isbst = true;
            return lastval;
        }
        Info* left = solve(root->left);
        Info* right = solve(root->right);

        Info* currInfo = new Info();
        currInfo->maxi = max(right->maxi, root->val);
        currInfo->mini = min(left->mini, root->val);

        if(left->isbst && right->isbst && root->val > left->maxi && root->val < right->mini){
            //this node is also a valid bst
            currInfo->isbst = true;
            currInfo->sum = left->sum + right->sum + root->val;
            
        }
        else{
            currInfo->isbst = false;
            currInfo->sum =0;
        }
        maxSum = max(maxSum , currInfo->sum);
        return currInfo;
    }
    int maxSumBST(TreeNode* root) {
        Info* rootval= solve(root);
        return maxSum;
    }
};