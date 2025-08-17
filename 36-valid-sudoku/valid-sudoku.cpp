class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i =0; i<9; i++){
            vector<bool> vis(10, false);

            for(int j = 0; j<9; j++){
                if(board[i][j] == '.') continue;

                if(vis[board[i][j] -'0'] == false){
                    vis[board[i][j] - '0'] = true;
                }
                else{
                    return false;
                }
            }
        }

        for(int i =0; i<9; i++){
            vector<bool> vis(10, false);

            for(int j = 0; j<9; j++){
                if(board[j][i] == '.') continue;

                if(!vis[board[j][i]-'0']){
                    vis[board[j][i]-'0'] = true;
                }
                else{
                    return false;
                }
            }
        }

        for(int i =0; i<3; i++){
            for(int j =0; j<3; j++){
                
                vector<bool> vis(10, false);
                for(int m =0; m<3; m++){
                    for(int n =0; n<3; n++){

                        int row = i*3 +m;
                        int col = j*3 +n;
                        if(board[row][col] == '.') continue;

                        if(!vis[board[row][col]-'0']){
                            vis[board[row][col]-'0'] = true;
                        }
                        else{
                            return false;
                        }
                    }

                }
            }
        }
        return true;




    }
};