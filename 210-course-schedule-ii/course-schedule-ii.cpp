class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // build graph
        for(auto &p : prerequisites){
            int a = p[0], b = p[1];
            adj[b].push_back(a);  // b → a
            indegree[a]++;
        }
        
        queue<int> q;
        
        // push all 0 indegree nodes
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }
        
        // check cycle
        if(ans.size() == numCourses) return ans;
        return {};
    }
};