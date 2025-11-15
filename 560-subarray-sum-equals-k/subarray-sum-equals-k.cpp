class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // if(k==0) return 0;
        unordered_map <int,int> prefix_sum;
        prefix_sum[0]=1;
        int sum =0;
        int ans =0;


        for(int i =0; i< nums.size() ; i++){
            sum += nums[i];

            if(prefix_sum.find(sum-k) != prefix_sum.end()){
                ans += prefix_sum[sum-k];
            }

            prefix_sum[sum] ++;
            

        }
        return ans;
        


        
    }
};