class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr)
            return;

        nodes.push_back(root);

        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }

    void flatten(TreeNode* root) {

        if (root == nullptr)
            return;

        vector<TreeNode*> nodes;

        // Store nodes in preorder
        preorder(root, nodes);

        // Connect them like a linked list
        for (int i = 0; i < nodes.size() - 1; i++) {
            nodes[i]->left = nullptr;
            nodes[i]->right = nodes[i + 1];
        }

        // Last node
        nodes.back()->left = nullptr;
        nodes.back()->right = nullptr;
    }
};