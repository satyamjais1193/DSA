class Solution {
public:
    int solvetabu(vector<int>& nums){
        vector<int>dp(nums.size()+2, 0);
        int n = nums.size();

        for(int i =n-1; i>=0; i--){
            int option1= nums[i] + dp[i+2];
            int option2= dp[i+1];

            dp[i] = max(option1, option2);            
        }
        


        return dp[0];

    }

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

        return solvetabu(nums);

        vector<int>dp(nums.size(), -1);
        int i=0;

        return solveusingdp(nums,i,dp);

        
    }

};