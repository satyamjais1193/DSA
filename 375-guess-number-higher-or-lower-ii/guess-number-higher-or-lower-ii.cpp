class Solution {
public:
    vector< vector<int>> dp;
    int solve (int s, int e){
        if(s>=e) return 0;

        if(dp[s][e] != -1) return dp[s][e];

        int ans = 1e9;
        for(int i = s;i <= e; i++){
            int rec = i + max(solve( s, i-1 ) , solve( i+1, e));
            ans = min( rec, ans);
        }
        return dp[s][e] = ans;
    }
    
    int getMoneyAmount(int n) {
        dp.assign( n+1, vector<int>( n+1, -1));
        return solve( 1, n);
    }
};