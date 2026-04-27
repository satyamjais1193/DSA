class Solution {
public:
    int solveusingdp(vector<int>& nums, int i,vector<int>& dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int option1= nums[i] + solveusingdp(nums, i+2, dp);
        int option2= solveusingdp(nums, i+1,dp);

        dp[i] = max(option1, option2);

        return dp[i];

    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        int i=0;

        return solveusingdp(nums,i,dp);

        
    }

};