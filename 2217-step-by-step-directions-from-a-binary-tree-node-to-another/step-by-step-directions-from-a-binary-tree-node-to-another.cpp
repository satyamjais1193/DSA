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
    TreeNode* start = nullptr;
    TreeNode* end = nullptr;
    string ans = "";

    unordered_map<TreeNode*, TreeNode*> prnt;
    unordered_map<TreeNode*, bool> vis;
    
    void markprnt(TreeNode* root, int s, int e){
        if(!root) return ;
        
        if(root->val == s) start = root;
        if(root->val == e) end = root;
        
        vis[root] = false;
        
        if(root->left) prnt[root->left] = root;
        if(root->right) prnt[root->right] = root;
        
        markprnt(root->left,  s ,e);
        markprnt(root->right, s,e);
    }

    void dfs(TreeNode* root, TreeNode*& end, string& temp){
        if(!root) return ;
        if(vis[root]) return;

        if(root == end && ans.size()< temp.size()){
            ans = temp;
            return ;
        }
        
        vis[root] = true;
        
        if(root->left){
            temp += 'L';
            dfs(root->left, end, temp);
            temp.pop_back();
        } 
        if(root->right){
            temp += 'R';
            dfs(root->right, end, temp);
            temp.pop_back();
        }
        if(prnt[root]){
            temp += 'U';
            dfs(prnt[root], end, temp);
            temp.pop_back();
        }

        vis[root] = false;

    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        
        string temp = "";
        markprnt(root,startValue,destValue );
        dfs(start, end, temp);
        return ans;
    }
};