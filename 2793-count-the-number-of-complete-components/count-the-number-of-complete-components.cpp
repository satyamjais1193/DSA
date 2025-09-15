class Solution {
public:

    bool traverse(int root, map<int, vector<int>> &adjList, vector<bool>& visit){
        queue<int> q;
        q.push(root);
        visit[root] = true;
        bool iscomplete = false;
        int d_edge =0;
        int nodes =0;
        // int min_nbr = INT_MAX;

        while(!q.empty()){
            int front = q.front();
            q.pop();
            nodes ++;

            vector<int> nbr = adjList[front];
            // int n =nbr.size();
            // min_nbr = min(min_nbr,n );
            
            for(int child : nbr){
                d_edge++; 
                if(!visit[child]){
                    visit[child] = true;
                    q.push(child);

                }
            }
        }
        d_edge /=2;
        return (d_edge == nodes * (nodes - 1) / 2);
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        map<int, vector<int>> adjList;
                for(int i = 0; i < n; i++) {
            adjList[i] = {};
        }
        for(int i =0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visit(n, false);
        int count =0;
        for(int i =0; i<n; i++){
            if(!visit[i]){
                 bool iscompl = traverse(i, adjList, visit);
                if(iscompl)
                count++;
            }
        }
        return count;
    }
};