class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix = 0;
        int total = 0;
        for(auto n: nums) total += n;

        for( int i =0; i< nums.size(); i++){
            int rightsum = total - prefix- nums[i];
            if(rightsum == prefix) return i;

            prefix += nums[i];
        }
        return -1;
    }
};