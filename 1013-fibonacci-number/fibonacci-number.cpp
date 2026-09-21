class Solution {
public:
    int solve (int n, vector<int>&dp){
        if (n ==0) return 0;
        if (n ==1) return 1; 
        if(dp[n] != -1){
            return dp[n];
        }

        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }
    int solvetabu(int n){
        vector<int> dp(n+1, 0);

        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i< n+1; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];

    }
    int so(int n){
        // vector<int> dp(n+1, 0);

        int prev  = 1;
        int nextprev = 0;

        for(int i = 2; i< n+1; i++){
            int curr = prev + nextprev;
            nextprev= prev;
            prev = curr;
        }
        return prev;

    }

    int fib(int n) {
        if(n ==0) return 0;
        if(n ==1) return 1;
        return so(n);

        return solvetabu(n);

        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};