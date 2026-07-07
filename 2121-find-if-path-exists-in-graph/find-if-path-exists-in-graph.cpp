class Solution {
public:
    unordered_map< int, list<int>> adjList;
    unordered_map< int, bool> visit;

    void dfs(int node, int destination){
        //base case
        visit[node] = true;
        if(node == destination) return;
        
        for(auto nbr : adjList[node]){
            if(!visit[nbr]){
                dfs(nbr, destination);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(auto e : edges){
            adjList[ e[0]].push_back(e[1]);
            adjList[ e[1]].push_back(e[0]);

            // visit[e[0]] = false;
        }

        dfs(source, destination);

        return (visit[destination] == true);


    }
};