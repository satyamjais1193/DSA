class Solution {
public:
    int solve(vector<int>& coins, int amount, int index, vector< vector<int>> &dp){
        //base case
        if(amount == 0){
            return 1;
        }
        if(index >= coins.size() || amount <0){
            return 0;
        }
        if(dp[amount][index] != -1) return dp[amount][ index];

        //ek case mai kerunga
        int ans =0;
        for(int i = index; i<coins.size() ; i++){
            ans += solve(coins, amount - coins[i], i ,dp);
        }

        return dp[amount][index] = ans;


    }

    int change(int amount,vector<int>& coins) {
        vector< vector<int>>dp(amount +1, vector<int>(coins.size() +1 ,-1));
        return solve(coins, amount , 0, dp);
    }
};