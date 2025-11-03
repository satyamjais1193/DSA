class Solution {
public:
    unordered_map<Node*, Node*> vis;  // map old_node → new_node

    void solve(Node* old_node, Node* new_node) {
        vis[old_node] = new_node;

        for (auto old_nbr : old_node->neighbors) {
            if (vis.find(old_nbr) == vis.end()) {
                //mean new node is created for this old node
                Node* new_nbr = new Node(old_nbr->val);
                new_node->neighbors.push_back(new_nbr);
                solve(old_nbr, new_nbr);
            } else {
                // If neighbor already cloned, just link it
                new_node->neighbors.push_back(vis[old_nbr]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;

        Node* new_node = new Node(node->val);
        solve(node, new_node);
        return new_node;
    }
};
