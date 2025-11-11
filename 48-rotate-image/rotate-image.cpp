class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        for(int i =0; i< row; i++){
            for(int j = i ; j < col ; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i =0; i< row; i++){
            // for(int j =i ; j < col ; col++){
                reverse(mat[i].begin(), mat[i].end());
            // }
        }

        
    }
};