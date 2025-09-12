class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        // Build graph
        for (auto &p : prerequisites) {
            int a = p[0], b = p[1];
            adj[b].push_back(a);   // b -> a
            indegree[a]++;
        }

        // Start with courses having no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int taken = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            taken++;

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return taken == numCourses;
    }
};