class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() -1;
        int n = nums.size();
        int ans= -1;

        //handle bounderies casees to avoid additional changes
        if(n == 1) return 0;
        //when first index is preak
        if(nums[0] > nums[1]) return 0;

        //when last index is peak
        if(nums[n-2] < nums[n-1]) return n-1;

        while( s<= e){
            int mid = s + (e-s)/2;
            if((nums[mid] > nums[mid +1]) && ( nums[mid]  > nums[mid-1])){
                //main codition of finding peak;
                return mid ;
            }
            else if( nums[mid] < nums[mid +1]){
                // ans  = mid;
                s = mid+1;
            }
            else{
                e = mid -1;
            }
        }
        return -1;

    }
};