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
    unordered_map<int, int> freq;
    int maxFreq =0;
    void solve(TreeNode* root){
        if(!root) return ;

        freq[root->val] ++;
        maxFreq = max(maxFreq, freq[root->val]);

        solve(root->left);
        solve(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        solve(root);
        vector<int> ans; 

        for(auto& [val, count] : freq){
            if(count == maxFreq){
                ans.push_back(val);
            }
        }
        return ans;

    }
};