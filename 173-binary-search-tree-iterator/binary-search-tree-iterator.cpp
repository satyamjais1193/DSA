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
class BSTIterator {
public:
    int index; 
    vector< int> inorder;
    TreeNode* root;
    void travel(TreeNode *root){
        if(!root) return;
        travel(root->left);
        inorder.push_back(root->val);
        travel(root->right);
    }
    BSTIterator(TreeNode* root) {
        this->root = root;
        this->index = -1;
        travel(root);
    }
    
    int next() {
        index ++;
        return inorder[index];
    }
    
    bool hasNext() {
        return (index +1 < inorder.size());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */