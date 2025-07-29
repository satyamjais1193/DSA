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

    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;

        TreeNode* x_parent=nullptr ;
        TreeNode* y_parent= nullptr ;
        // bool isFound = false;
        unordered_map<TreeNode*, TreeNode*> parent;

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int i = 0;
            int isFound = 0;
            while( i< size){
                TreeNode* front = q.front();
                q.pop();
                if(front ->val ==x ){
                    isFound ++;
                    x_parent = parent[front];
                } 
                if(front ->val == y){
                    isFound ++;
                    y_parent = parent[front];
                }

                if(front->left){
                    q.push(front->left);
                    parent[front->left] = front;
                } 
                if(front->right){
                    q.push(front->right);
                    parent[front->right] = front;
                } 
                i++;
            }
            if(isFound == 1){
                return false;
            }
            if(isFound == 2 && x_parent != y_parent){
                return true;
            }
        }
        return false;
        
    }
};