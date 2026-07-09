class Solution {
public:
    vector<vector<int>> vis;
    bool issafe(vector<vector<int>>& grid, int x, int y, int newx, int newy){
        if( newx>= 0 && newx< grid.size() && newy>=0 && newy< grid[0].size() && 
            vis[newx][newy] == false && grid[newx][newy] == 1){
                return true;
            }
        else{
            return false;
        }
    }
    int dfs(vector<vector<int>>& grid, int x, int y){
        vis[x][y] = true;

        //travel to nbr
        int dx[] ={0 , 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        int ans = 0;
        for(int i =0; i<4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];

            if(issafe(grid, x, y, newx, newy)){
                //can travel
                ans += dfs(grid, newx, newy);
            }
        }
        return ans + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxAns = 0;
        vis.assign(grid.size(), vector<int>(grid[0].size(), false));


        for(int i =0; i<grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(vis[i][j] == false && grid[i][j] == 1){
                    int dfsans = dfs(grid, i, j);
                    maxAns = max(maxAns, dfsans);
                }
            }
        }
        return maxAns;
    }
};