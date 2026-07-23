class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int>& stones, int ind, int sum){
        if(sum ==0) return true;
        if(ind >= stones.size()){
            return false;
        }
        if(dp[ind][sum]  != -1) return dp[ind][sum];


        bool ex = solve( stones, ind +1, sum);

        bool in = false;
        if( sum- stones[ind] >= 0){
            in = solve(stones, ind +1, sum - stones[ind]);
        }
        return dp[ind][sum] = in || ex;

    }
    int lastStoneWeightII(vector<int>& stones) {
        int sum =0; 

        for(int i = 0; i < stones.size(); i++){
            sum += stones[i];
        }
        dp.assign(stones.size(), vector<int>(sum + 1, -1));
        // as seacrch for only sum/2 as --- we are dividing it into two subset with - and + wala groups. thus max sum in that could be sum/2
        int ans = INT_MAX;
        for (int s = 0; s <= sum / 2; s++) {
            // 
            if (solve(stones, 0, s))
                ans = min(ans, sum - 2 * s);
        }
        return ans;

    }
};