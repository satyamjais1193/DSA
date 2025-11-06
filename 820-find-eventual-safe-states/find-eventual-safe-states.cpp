class Solution {
public:
    bool checksafe(vector<vector<int>>& graph, int node_ind, vector<int> &vis){
        if(vis[node_ind] != 0){ // \U0001f539 handle already visited states
            return (vis[node_ind] == 2); // if safe return true, else false
        }

        bool ans = true;
        vis[node_ind] = 1;
        for(int i =0; i< graph[node_ind].size() ; i++){
            ans = ans & checksafe(graph, graph[node_ind][i], vis);
            if( !ans){
                return false;
            }
        }
        vis[node_ind] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<int> safenode;

        for(int i =0; i<graph.size(); i++){
            bool ans = checksafe(graph, i, vis);

            if(ans)
                safenode.push_back(i);
        }
        return safenode;
        
    }
};