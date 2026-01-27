class Solution {
public:
    bool isSafe(vector<vector<char>>& board, string& word,int row, int col, int index,vector<vector<bool>>& vis){
        if( row >=0 && col >=0 && row < board.size() && col < board[0].size() && vis[row][col] == false && word[index] == board[row][col] )
            return true;
        

        return false;
    }

    bool solve(vector<vector<char>>& board, string& word,int row, int col, int index,vector<vector<bool>>& vis){
        //base case - pending
        if(index == word.size() -1) return true;

        // if()

        //ek case mai kerunga
        vis[row][col] = true;
        // if(word[index] == board[row][col]) index ++;
        bool ans = false;
        //right
        if(isSafe(board, word, row +1, col, index +1, vis)){
            ans = ans || solve(board, word, row +1, col, index +1 , vis );
        }

        //down
        if(isSafe(board, word, row , col +1, index +1, vis)){
            ans = ans ||solve(board, word, row , col+1, index +1, vis );
        }

        // left
        if(isSafe(board, word, row -1, col, index +1, vis)){
            ans = ans || solve(board, word, row -1, col, index +1, vis );
        }

        //up
        if(isSafe(board, word, row , col-1, index +1, vis)){
            ans = ans || solve(board, word, row , col-1, index  +1, vis );
        }
        vis[row][col] = false;
        if(word[index] == board[row][col]) index --;

        return ans;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        // ✅ try all starting points
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};