class Solution {
public:
    int pivotIndex( vector<int>& nums){
        int n=nums.size();
        int s=0;
        int e=n-1;

        while(s<=e){
            int mid=s +(e-s)/2;
            if(s==e){
                return s;
            }
            if (mid < e && nums[mid] > nums[mid + 1]) {
                return mid;
            }
            if (mid > s && nums[mid] < nums[mid - 1]) {
                return mid - 1;
            }
            if (nums[s] > nums[mid]) {
                e = mid - 1;
            } else { 
                s = mid + 1;
            }
        }

        return s;
         

    }
    int findMin(vector<int>& nums) {

        int pivot = pivotIndex(nums );
        if (pivot != nums.size() -1) {
            pivot ++;
        }
        return min(nums[pivot], nums[0]);
        

    }
};