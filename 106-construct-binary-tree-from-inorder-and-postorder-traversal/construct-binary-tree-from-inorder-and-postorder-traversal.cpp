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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int s_in , int e_in, int& postInd ){
        //base case
        if(s_in > e_in || postInd < 0){
            return nullptr;
        }

        //nrl
        TreeNode* newNode = new TreeNode(postorder[postInd]);

        int inInd = -1;

        for(int i = s_in; i<=e_in; i++){
            if(inorder[i] == postorder[postInd]){
                inInd = i;
                break;
            }
        }

        //r
        postInd--;
        newNode->right = solve(inorder, postorder,inInd +1, e_in, postInd);
        newNode->left = solve(inorder, postorder,s_in, inInd -1, postInd);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postInd = postorder.size() -1;
        TreeNode* root = solve( inorder, postorder, 0, inorder.size() -1, postInd);
        return root;   
    }
};