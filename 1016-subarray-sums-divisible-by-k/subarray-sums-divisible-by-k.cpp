class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        //store freq of prefix sum % k which
        unordered_map<int,int> prefixrem;
        prefixrem[0] = 1;

        int ans = 0;
        long long prefixsum = 0;
        for(int i =0; i<nums.size(); i++){
            prefixsum += nums[i];
            
            int rem = prefixsum %  k;
            if(rem < 0){
                rem += k;
            }

            // if(need)
            if( prefixrem.find(rem) != prefixrem.end() ){
                // /?>?/?/ found rem
                ans += prefixrem[rem];
            }

            prefixrem[rem] ++;
        }
        return ans;

    }
};
// ;k = 5:$0