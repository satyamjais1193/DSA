class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        stack<TreeNode*> st;

        while (root != NULL || !st.empty()) {

            // Keep going LEFT
            while (root != NULL) {
                st.push(root);
                root = root->left;
            }

            // Take the leftmost node
            root = st.top();
            st.pop();

            // Process ROOT
            ans.push_back(root->val);

            // Now go RIGHT
            root = root->right;
        }

        return ans;
    }
};