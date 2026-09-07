/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void seri(TreeNode* root, string& ans){
        if(!root){
            ans += "#,";//must use the double inverted comma
            return;
        }

        ans += to_string(root->val) + ",";

        seri(root->left, ans);
        seri(root->right, ans);

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        seri(root, ans);
        return ans;
    }

    TreeNode* deseri(stringstream& ss){
        string val;
        getline(ss, val, ',');

        if(val == "#") return nullptr;

        TreeNode* newnode = new TreeNode(stoi(val));

        newnode->left = deseri(ss);
        newnode->right = deseri(ss);
        return newnode;
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deseri(ss);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));