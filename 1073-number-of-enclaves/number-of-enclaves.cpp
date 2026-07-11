class Solution {
public:
    vector<vector<bool>> vis;
    bool safe(vector<vector<int>>& grid, int x, int y){
        if(x >=0 && x<grid.size() && y<grid[0].size() && y>=0 && !vis[x][y] && grid[x][y] ==1){
            return true;
        }
        else{
            return false;
        }
    }
    int dfs(vector<vector<int>>& grid, int x, int y){
        vis[x][y] = true;

        //travel to nbr
        int ans =0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i =0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(safe(grid, nx, ny)){
                ans += dfs(grid, nx, ny);
            }
        }
        return ans + 1;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vis.assign(n, vector<bool>(m, false));
        
        int noreq = 0;
        for(int col = 0; col<m; col ++){
            if(grid[0][col] == 1 && !vis[0][col]){
                noreq += dfs(grid, 0, col);
                cout<<1;
            }
            if(grid[n-1][col] == 1 && !vis[n-1][col]){
                noreq += dfs(grid, n-1, col);
                cout<<1;
            }
        }
        cout<<endl;
        for(int row = 0; row<n; row ++){
            if(grid[row][0] == 1 && !vis[row][0]){
                noreq += dfs(grid, row, 0);
                cout<<1;
            }
            if(grid[row][m-1] == 1 && !vis[row][m-1]){
                noreq += dfs(grid, row, m-1);
                cout<<1;
            }
        }
        cout<<endl;
        int ans =0;
        for( int i =1; i<n-1; i++){
            for(int j = 1; j<m-1; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int dfsans =dfs(grid, i, j);
                    cout<<2;
                    cout<<i<<" "<<j<<" "<< dfsans<<endl;
                    ans += dfsans;
                }
            }
        }
        cout<<ans;
        return ans;

    }
};