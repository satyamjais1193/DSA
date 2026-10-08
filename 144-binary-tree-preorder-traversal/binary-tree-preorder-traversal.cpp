class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preorder;

        // If tree is empty, return empty vector
        if (root == NULL)
            return preorder;

        // Stack is used to simulate recursion
        stack<TreeNode*> st;

        // Start with root
        st.push(root);

        while (!st.empty()) {

            // Take the top node
            root = st.top();
            st.pop();

            // Process the current node first
            preorder.push_back(root->val);

            // Push RIGHT first
            // because stack follows LIFO,
            // so LEFT will be processed first.
            if (root->right != NULL) {
                st.push(root->right);
            }

            // Push LEFT after right
            if (root->left != NULL) {
                st.push(root->left);
            }
        }

        return preorder;
    }
};