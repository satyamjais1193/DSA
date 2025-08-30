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
    vector<int> nodes;
    void travel(TreeNode* root){
        if(!root) return;
        travel(root->left);
        nodes.push_back(root->val);
        travel(root->right);
    }
    void makeGst(TreeNode* root , vector<int>& sums){
        if(!root) return;
        makeGst(root->left, sums);
        // nodes.push_back(root->val);
        int index = lower_bound(nodes.begin(), nodes.end(), root->val) - nodes.begin();
        root-> val = sums[index];
        makeGst(root->right, sums);
    }

    TreeNode* bstToGst(TreeNode* root) {
        travel(root);
        // sort(nodes.begin(), nodes.end());
        vector<int> sums(nodes.size());
        int s =0;
        for(int i = nodes.size()-1 ; i>=0; i--){
            s += nodes[i];
            sums[i] = s;
        }
        makeGst(root, sums);
        return root;

        // sort(sums.begin(), sums.end());






    }
};