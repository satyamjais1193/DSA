class Solution {
    // int[][] dp;
    // public int solve(int[] nums, int index, int prevIndex) {

    //     // Base case
    //     if (index == nums.length) {
    //         return 0;
    //     }

    //     // prevIndex + 1 because prevIndex can be -1
    //     if (dp[index][prevIndex + 1] != -1) {
    //         return dp[index][prevIndex + 1];
    //     }

    //     // EXCLUDE
    //     int exclude = solve(nums, index + 1, prevIndex);

    //     // INCLUDE
    //     int include = 0;

    //     if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
    //         include = 1 + solve(nums, index + 1, index);
    //     }

    //     return dp[index][prevIndex + 1] =
    //             Math.max(include, exclude);
    // }
    public int solveTabu(int[] nums){
        int n = nums.length;
        int[][] dp = new int[n+1][n+1];


        for(int i =0; i<n+1; i++){
            Arrays.fill(dp[i], 0);
        }

        for(int index = n -1; index >=0; index--){
            for(int prevIndex = index -1; prevIndex >=-1; prevIndex--){

                int exclude = dp[index + 1][ prevIndex +1];

                // INCLUDE
                int include = 0;

                if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
                    include = 1 + dp[index + 1][index +1];
                }

                dp[index][prevIndex + 1] = Math.max(include, exclude);

            }    
        }
        return dp[0][-1 +1];
    }
    public int lengthOfLIS(int[] nums) {
        //  int n = nums.length;

        // dp = new int[n][n + 1];

        // for (int i = 0; i < n; i++) {
        //     Arrays.fill(dp[i], -1);
        // }

        // return solve(nums, 0, -1);

        return solveTabu(nums);
    }
}