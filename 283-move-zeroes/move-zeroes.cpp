class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i =0;// iterator
        int j = 0;// to place non zero number
        int n = nums.size();
        while(i< n){
            if(nums[i] != 0){
                nums[j] = nums[i];
                j++;
                i++;
            }
            else{
                i++;
            }
        }
        while( j< n){
            nums[j] = 0;
            j++;
        }
        
    }
};