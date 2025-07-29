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
    void inorder_trv(TreeNode* root){
        if(!root) return;

        inorder_trv(root->left);
        inorder.push_back(root->val);
        inorder_trv(root->right);
    }
    TreeNode* createBST(TreeNode* root, int s, int e){
        if(s> e) return nullptr;

        int mid = s + (e-s)/2;

        TreeNode* newNode = new TreeNode(inorder[mid]);

        newNode->left = createBST(newNode, s, mid-1);
        newNode->right = createBST(newNode, mid +1, e);

        return newNode;

    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder_trv(root);
        int s =0;
        int e = inorder.size() -1;

        int mid = s + (e-s)/2;

        TreeNode* head = new TreeNode(inorder[mid]);

        head->left = createBST(head, s, mid-1);
        head->right = createBST(head, mid +1, e);
        return head;



        

    }
};