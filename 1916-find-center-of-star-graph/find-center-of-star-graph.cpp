class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        if(edges.size() <2){
            return 1;
        }
        else{
            for(int i =0; i<2; i++){
                int fist = edges[0][i];
                for(int j=0; j<2; j++){
                    if (fist == edges[1][j])
                        return fist;

                }
            }
        }
        return 0;

        
    }
};