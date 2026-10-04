class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        // {neighbor, cost}
        // cost = 1 -> original edge points away from 0, so reverse it
        // cost = 0 -> original edge already points toward 0

        vector<vector<pair<int, int>>> adj(n);

        for (auto edge : connections) {

            int u = edge[0];
            int v = edge[1];

            // Original direction: u -> v
            adj[u].push_back({v, 1});

            // We can traverse v -> u in our BFS
            // Original road is actually u -> v, so no reversal needed
            adj[v].push_back({u, 0});
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int ans = 0;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {

                int next = it.first;
                int cost = it.second;

                if (vis[next])
                    continue;

                vis[next] = true;

                // If cost == 1, edge is going away from 0
                // so we need to reverse it.
                ans += cost;

                q.push(next);
            }
        }

        return ans;
    }
};