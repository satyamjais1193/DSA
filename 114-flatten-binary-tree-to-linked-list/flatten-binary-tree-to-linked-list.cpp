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
    vector<int> inorder;
    void inorder_tr(TreeNode* root){
        if(!root) return ;

        inorder.push_back(root->val);
        cout<<root->val<<" ";
        inorder_tr(root->left);
        inorder_tr(root->right);

    }
    void create(TreeNode * root, int& index){
        if(index >= inorder.size()){
            return ;
        }

        TreeNode * newNode = new TreeNode(inorder[index]);
        index++;

        root->left = nullptr;
        root->right = newNode;
        create(newNode , index);

        // return root;

    }
    void flatten(TreeNode* root) {
        inorder_tr(root);
        int index =1;

        create( root,index);
        // root = head;


    }
};