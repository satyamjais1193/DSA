class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // vector<int> sort_nums= nums;
        // sort(sort_nums.begin(), sort_nums.end());
        next_permutation(nums.begin(), nums.end());
        
        

    }
};