class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int start =0; 
        int end =0;
        int n = nums.size();
        int count = 0;
        int ans  = 0;

        int peven =0;

        while( end < n){
            if(nums[end]&1){
                //odd hai
                count ++;
            }

            //as start will always point 
            if(count >k && (nums[start] %2 == 1)){
                start ++;
                count --;
                peven = 0;
            }

            if(count == k){
                //shrink and count prev even number;
                while(nums[start] %2 ==0){
                    start ++;
                    peven ++;
                }
                ans += peven + 1;
            }
            end ++;


        }
        return ans;


    }
};