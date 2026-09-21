class Solution {
public:
    // int solve(string& a, string& b, int i , int j, vector<vector<int>>& dp) {
    //     if( i >= a.length()){
    //         return 0;
    //     }
    //     if( j >= b.length()){
    //         return 0;
    //     }

    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }

    //     int ans =0;
    //     if(a[i]== b[j]){
    //         ans = 1+ solve(a,b, i+1, j+1  ,dp);
    //     }
    //     else{
    //         ans = 0 + max(solve(a,b, i, j+1, dp), solve(a, b, i+1, j, dp));
    //     }
    //     dp[i][j] = ans;
    //     return dp[i][j];
    // }
    int solvetabu(string& a, string& b) {

        int n = a.size();
        int m = b.size();


        vector<vector<int>> dp (a.length() +1, vector<int>(b.length() +1 , 0));

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                int ans =0;
                if(a[i]== b[j]){
                    ans = 1+ dp[i+1][ j+1];
                }
                else{
                    ans = 0 + max(dp[i][j+1], dp[i+1][j]);
                }
                dp[i][j] = ans;
            }
        }


        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {

        return solvetabu(text1, text2);
        // int i=0;
        // int j=0;


        // vector<vector<int>> dp (text1.length() +1, vector<int>(text2.length() +1 , -1));

        // return solve(text1, text2, i, j , dp);
        
        
    }
};