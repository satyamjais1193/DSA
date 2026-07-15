class Solution {
public:
    const  long long  mod = 1e9 +7;
    // void dfs( vector< vector<pair<int,int>>>& adj, int node,long long timetaken, long long& min_time, long long& ans, vector<bool>& vis){
        
    //     if(node == adj.size()-1 && timetaken == min_time){
    //         ans = ans%mod + 1;
    //         return;
    //     }

    //     vis[node] = true;

    //     for(auto& [nbr, wt] : adj[node]){
    //         if(!vis[nbr] && timetaken + wt <= min_time){
    //             dfs(adj, nbr, timetaken +wt, min_time, ans, vis);
    //         }
    //     }
    //     vis[node] = false;

    // }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<bool> vis (n, false);
        vector<long long> dist(n, LLONG_MAX);
        vector<long long > ways(n, 0);
        priority_queue< pair<long long, long long> , vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

        vector< vector<pair<int,int>>> adj(n);

        for(auto r : roads){
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        pq.push({0, 0});//time, node
        dist[0] = 0;
        ways[0] =1;

        while(!pq.empty()){
            auto top= pq.top();
            pq.pop();
            int node = top.second;
            
            if(vis[node]) continue;

            vis[node] = true;

            for(auto& [nbr, wt] : adj[node]){
                if(!vis[nbr] && dist[node] + wt < dist[nbr]){
                    dist[nbr] = dist[node] + wt;
                    ways[nbr] = ways[node];
                    pq.push({dist[nbr],nbr });
                }
                else if(dist[node] + wt == dist[nbr]){
                    ways[nbr] = (ways[node] + ways[nbr]) % mod;
                }
            }
        }

        return ways[n-1] % mod;

        // fill(vis.begin(), vis.end(), false);

        // long long min_time = dist[n-1];
        // long long ans = 0;

        // dfs(adj, 0, 0 , min_time, ans, vis);
        // return ans;

    }
};