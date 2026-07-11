class Solution {
public:
    vector<vector< pair<bool, int> >> vis;

    bool safe(vector<vector<int>>& grid, int x, int y){
        if( x >=0 && x< grid.size() && y>=0 && y< grid.size()
            && !vis[x][y].first && grid[x][y] == 1){
                return true;
            }
        else{
            return false;
        }
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int id){
        vis[x][y].first = true;
        vis[x][y].second = id;

        //visiting nbr
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        int ans =0;
        for(int i =0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];

            if(safe(grid, newx, newy)){
                ans += dfs(grid, newx, newy, id);
            }
        }
        return ans + 1;

    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vis.assign(n, vector< pair<bool, int>>(n, {false, -1}));
        unordered_map<int,int> idtoarea;

        //marking islands
        int maxarea = 0;
        int id =1;
        for(int i=0; i<n; i++){
            for(int j =0; j< n; j++){
                if(safe(grid, i, j)){
                    int area = dfs(grid, i, j, id);
                    maxarea = max(area, maxarea);
                    idtoarea[id] = area;
                    id++;
                }
            }
        }

        //checking possiblities
        
        for(int i=0; i<n; i++){
            for(int j =0; j< n; j++){
                int ans = 0;
                
                if(grid[i][j] == 0){
                    int dx[] = {0,0,1,-1};
                    int dy[] = {1,-1,0,0};
                    unordered_map< int, bool> include;
                    
                    for(int k =0; k<4; k++){
                        int newx = i + dx[k];
                        int newy = j + dy[k];
                        
                        if(newx >=0 && newx< grid.size() && newy>=0 && newy< grid.size() && grid[newx][newy] == 1  && include[vis[newx][newy].second] == false){
                            include[vis[newx][newy].second] = true;
                            ans += idtoarea[ vis[newx][newy].second ];
                        }
                    }
                }
                maxarea = max(maxarea, ans +1);
            }
        }
        return maxarea;
    }
};