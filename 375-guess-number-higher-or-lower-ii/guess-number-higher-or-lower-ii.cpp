class Solution {
public:
    
    // int solve (int s, int e){
    //     if(s>=e) return 0;

    //     if(dp[s][e] != -1) return dp[s][e];

    //     int ans = 1e9;
    //     for(int i = s;i <= e; i++){
    //         int rec = i + max(solve( s, i-1 ) , solve( i+1, e));
    //         ans = min( rec, ans);
    //     }
    //     return dp[s][e] = ans;
    // }

    int solvetabu(int n){
        vector< vector<int>> dp( n+2, vector<int>( n+2, 0));


        for( int s = n ; s>=1; s--){
            for(int e = 1; e<=n; e++ ){
                if(s>=e) continue;
                int ans = 1e9;
                for(int i = s;i <= e; i++){
                    int rec = i + max(dp[s][i-1] , dp[i+1][e]);
                    ans = min( rec, ans);
                }
                dp[s][e] = ans;
            }
        }
        return dp[1][n];
    }
    
    int getMoneyAmount(int n) {
        return solvetabu(n);
        // dp.assign( n+1, vector<int>( n+1, -1));
        // return solve( 1, n);
    }
};