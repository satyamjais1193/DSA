class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int> comb, vector<vector<int>> &ans ) {
        //base case
        if(index >= nums.size()){
            ans.push_back(comb);
            return;
        }
        //ek case mai kerunag
        
        solve(nums, index +1, comb, ans);
        comb.push_back(nums[index]);
        solve(nums, index +1, comb, ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> comb;
        vector<vector<int>> ans;
        solve(nums, 0, comb, ans);
        return ans;
        
    }
};