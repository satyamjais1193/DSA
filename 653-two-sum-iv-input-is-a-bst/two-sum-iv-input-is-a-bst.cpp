class BSTIterator {
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            if(reverse)
                node = node->right;   // reverse inorder
            else
                node = node->left;    // normal inorder
        }
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();

        if(!reverse)
            pushAll(temp->right);
        else
            pushAll(temp->left);

        return temp->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};


class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator left(root, false);   // smallest iterator
        BSTIterator right(root, true);   // largest iterator

        int i = left.next();
        int j = right.next();

        while(i < j) {
            int sum = i + j;

            if(sum == k)
                return true;

            else if(sum < k) {
                if(left.hasNext())
                    i = left.next();
                else break;
            }
            else {
                if(right.hasNext())
                    j = right.next();
                else break;
            }
        }

        return false;
    }
};
