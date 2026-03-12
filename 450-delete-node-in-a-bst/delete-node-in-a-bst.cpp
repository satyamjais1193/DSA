class Solution {
public:
    
    TreeNode* findMin(TreeNode* root){
        while(root->left)
            root = root->left;
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        
        else{
            if(!root->left && !root->right)
                return nullptr;
            
            else if(!root->left)
                return root->right;
            
            else if(!root->right)
                return root->left;
            
            else{
                TreeNode* successor = findMin(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right, successor->val);
            }
        }
        
        return root;
    }
};