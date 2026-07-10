class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int> ans(nums.size() * 2);
        int n = nums.size();
        for(int i = 0; i< nums.size(); i++){
            ans[i] = nums[i];
            ans[i + n] = nums[n - i - 1];
        }
        return ans;    
    }
};