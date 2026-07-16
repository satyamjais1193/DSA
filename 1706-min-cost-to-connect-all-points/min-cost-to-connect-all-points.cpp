class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<vector<pair<int, int>>> adj(n);

        // Build complete graph
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<bool> vis(n, false);

        pq.push({0, 0}); // {weight, node}

        int ans = 0;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (vis[node])
                continue;

            vis[node] = true;
            ans += wt;

            for (auto [nbr, edgeWt] : adj[node]) {
                if (!vis[nbr]) {
                    pq.push({edgeWt, nbr});
                }
            }
        }

        return ans;
    }
};