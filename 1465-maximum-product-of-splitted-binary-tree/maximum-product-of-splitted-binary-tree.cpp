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
    unordered_map<TreeNode* , long long> mapp;
    long long  maxi = INT_MIN;
    static const long long  mod = 1e9 + 7;

    long long mapsubTree(TreeNode* root){
        if(!root) return 0;

        long long lsum = mapsubTree(root->left);
        long long rsum = mapsubTree(root->right);

        mapp[root] = root->val + lsum + rsum;
        return root-> val + lsum + rsum;
    }

    void maxPro(TreeNode* root, long long & totalsum){
        if(!root) return ;

        long long option1 = INT_MIN;
        long long option2 = INT_MIN;
        if(root->left){
            option1 = (((mapp[root->left])) * ((totalsum - mapp[root->left])));
        }
        if(root->right){
            option2 = (((mapp[root->right])) * ((totalsum - mapp[root->right])));
        }
        
        maxi = max({maxi, option1, option2});

        maxPro(root->left, totalsum);
        maxPro(root->right, totalsum);
    }

    int maxProduct(TreeNode* root) {
        long long totalsum =  mapsubTree(root);
        cout<<totalsum;
        maxPro(root, totalsum);

        return  maxi%mod;

    }
};