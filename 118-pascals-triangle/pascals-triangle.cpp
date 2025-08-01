class Solution {
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> tri;

        tri.push_back({1});
        if (rows == 1) return tri;

        
        tri.push_back({1, 1});
        if (rows == 2) return tri;

        for( int i=2; i<rows; i++){
            vector<int> newrow(i+1, 1);

            int size = tri[i-1].size();

            for(int j=0; j<size-1 ; j++){
                newrow[j+1]= tri[i-1][j] + tri[i-1][j+1];
            }

            tri.push_back(newrow);
        }
        return tri;


    }
};