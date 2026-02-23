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
    vector< pair<int, TreeNode*> > inorder;

    void travel(TreeNode* root){
        if(!root){
            return ;
        }

        travel(root->left);
        inorder.push_back({root->val, root});
        travel(root->right);
    }
    void recoverTree(TreeNode* root) {
        travel(root);

        vector< pair<int, TreeNode*> > copy(inorder);
        sort(copy.begin(), copy.end());

        int j =0; 
        for(; j< inorder.size(); j++){
            if(inorder[j].first != copy[j].first){
                break;
            }
        }
        
        

        // int i =0;
        // while( i +1 < inorder.size() && inorder[i+1].first > inorder[i].first ){
        //     i ++;
        // }

        // int target = i;
        // i++;
        // while(i<inorder.size() && inorder[target].first > inorder[target].first){
        //     i++;
        // }

        inorder[j].second->val = copy[j].first;
        copy[j].second->val = inorder[j].first;
        cout<<inorder[j].first<<" "<<copy[j].first;



        // if( i  < inorder.size()){
        //     // swap(inorder[i+1], inorder[target]);
        //     inorder[target].second->val = inorder[i+1].first;
        //     inorder[i+1].second->val = inorder[target].first;
        //     cout<<inorder[target].first<<" "<<inorder[i+1].first;
        // }
        // else{
        //     // swap(inorder[i], inorder[target]);
        //     inorder[target].second->val = inorder[i].first;
        //     inorder[i].second->val = inorder[target].first;
        //     cout<<inorder[target].first<<" "<<inorder[i].first;
        // }



    }
};