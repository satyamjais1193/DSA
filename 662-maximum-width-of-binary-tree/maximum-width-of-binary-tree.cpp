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
    int widthOfBinaryTree(TreeNode* root) {
        queue< pair<TreeNode*, long long> > q;
        int maxi = INT_MIN;
        q.push({root, 1});

        while(!q.empty()){

            int size = q.size();
            long long f = 0; 
            long long l = 0;
            long long minIndex = q.front().second;

            for(int i =0; i<size; i++){
                pair <TreeNode*, long long> p = q.front();
                q.pop();

                TreeNode* front = p.first;
                long long index = p.second - minIndex;
                if(i ==0) f = index;
                if(i == size-1) l = index;

                // if(front != nullptr){
                    if(front->left)
                        q.push({front->left, 2*index});
                    if(front -> right)
                        q.push({front->right, 2* index +1});
                // } 
                         
            }

            maxi = max(maxi, int(l - f +1));
        }
        return maxi;

    }
};