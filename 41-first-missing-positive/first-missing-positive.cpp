class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i =0; i< n; i++){
            while(nums[i] >=1 && nums[i] <= n){
                int curr = nums[i];

                int correct_ind = curr - 1;

                //at correct postion or duplicates
                if(nums[correct_ind] == curr){
                    break;
                }
                swap(nums[correct_ind], nums[i]);
            }
        }
         for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};