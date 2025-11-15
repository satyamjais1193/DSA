class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int pos_ind =0;
        for (int i=0; i< nums.size(); i++){
            if(nums[i] >= 0){
                ans[pos_ind] = nums[i];
                pos_ind += 2;
            }
        }

        int neg_ind = 1;
        for (int i=0; i< nums.size(); i++){
            if(nums[i] < 0){
                ans[neg_ind] = nums[i];
                neg_ind +=2 ;
            }
        }
        return ans;
        
    }
};