class Solution {
public:
    void dfs(int src, unordered_map<int, list<int>>& adjList,unordered_map<int, bool>& visit){
        visit[src] =true;

        for(auto nbr : adjList[src]){
            if(!visit[nbr]){
                dfs(nbr, adjList, visit);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& mat) {
        unordered_map<int, list<int>> adjList;
        int n = mat.size();
        for(int i =0; i< n; i++){
            for(int j =0; j<n; j++){
                if(mat[i][j] == 1 && i != j){
                    adjList[i].push_back(j);
                }
            }
        }

        unordered_map<int, bool> visit;

        int count = 0;
        for(int i =0; i<n; i++){
            if(!visit[i]){
                count ++;
                dfs(i, adjList, visit);
            }
        }
        return count;
    }
};