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
    //col row values
    //-- use multiset to store value in sorted oreder and allowed dulicates
    map<int, map<int, multiset<int>> >virtical;
    void dfs(TreeNode* root, int row, int col){
        if(!root) return;

        virtical[col][row].insert(root->val);

        dfs(root->left, row+1, col -1);
        dfs(root->right, row+1, col +1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0 , 0);
        // for(auto& m : virtical){
        //     sort(m.second.begin(), m.second.end());
        // }
        vector<vector<int>> ans;
        for(auto& col : virtical){
            vector<int> temp;
            for(auto&  row : col.second){
                
                for(auto val : row.second){
                    temp.push_back(val);
                }

                
            }
            ans.push_back(temp);
            // ans.push_back(m.second);
        }
        return ans;

    }
};