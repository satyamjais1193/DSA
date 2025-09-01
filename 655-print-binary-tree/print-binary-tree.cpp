class Solution {
public:
    int getHeight(TreeNode* root) {
        if (!root) return -1; 
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    void fill(TreeNode* root, int r, int left, int right, vector<vector<string>>& res) {
        if (!root) return;

        int mid = (left + right) / 2;
        res[r][mid] = to_string(root->val);

        fill(root->left, r + 1, left, mid - 1, res);
        fill(root->right, r + 1, mid + 1, right, res);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        int rows = height + 1;
        int cols = pow(2, height + 1) - 1;

        vector<vector<string>> res(rows, vector<string>(cols, ""));
        fill(root, 0, 0, cols - 1, res);
        return res;
    }
};
