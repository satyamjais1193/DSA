class Solution {
public:
    vector<vector<bool>> rowcheck, colcheck;
    vector<vector<vector<bool>>> sqcheck;

    bool checkSafe(vector<vector<char>>& result , int row, int col , char n){
        return ((rowcheck[row][n-'1'] == false) && colcheck[col][n-'1'] == false && sqcheck[row/3][col/3][n-'1'] == false);
    }
    bool solve(vector<vector<char>>& board, int row, int col, char ch){
        //base case
        if(col == 9 ){
            // board = result;
            return true;
        }
        if(row == 9){
             return solve(board, 0, col +1, '1');
        }

        // if(row == 0) n = '1';
        //hard filling 
        if(board[row][col] != '.'){
            return solve(board, row +1, col , ch);
        }


        for(char n ='1'; n<='9'; n++){

            if(checkSafe(board,row, col , n)){
                board[row][col] = n;
                rowcheck[row][ n-'1'] = true;
                colcheck[col][ n- '1'] = true;
                sqcheck[row/3][col/3][n -'1'] = true;

                // n++;
                if (solve(board, row + 1, col , n))
                    return true;

                board[row][col] = '.';
                rowcheck[row][ n-'1'] = false;
                colcheck[col][ n- '1'] = false;
                sqcheck[row/3][col/3][n -'1'] = false; 
            }
        }
        return false;
        

    }
    void solveSudoku(vector<vector<char>>& board) {
        // vector<vector<char>> result(board);
        rowcheck.assign(9, vector<bool>(9, false));
        colcheck.assign(9, vector<bool>(9, false));
        sqcheck.assign(3, vector<vector<bool>>(3, vector<bool>(9, false)));
        
        for(int i =0; i<9; i++){
            // vector<bool> vis(10, false);
            for(int j = 0; j<9; j++){
                if(board[i][j] != '.'){
                    rowcheck[i][ board[i][j] - '1'] = true;
                    colcheck[j][ board[i][j] - '1'] = true;
                    sqcheck[i/3][j/3][ board[i][j] - '1'] = true;
                } 
            }
        }
        // cout<<rowcheck<<endl;
        // cout<<colcheck<<endl;
        // cout<<sqcheck<<endl;
        solve(board,  0 , 0 , '1');

        return;

        
    }
};