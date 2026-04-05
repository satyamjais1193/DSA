class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;
        
        // Step 1: Push all rotten oranges & count fresh
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        // If no fresh oranges
        if(fresh == 0) return 0;
        
        int time = 0;
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        // Step 2: BFS
        while(!q.empty()) {
            int size = q.size();
            bool rotted = false;
            
            for(int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            
            // Increase time only if something rotted
            if(rotted) time++;
        }
        
        return fresh == 0 ? time : -1;
    }
};