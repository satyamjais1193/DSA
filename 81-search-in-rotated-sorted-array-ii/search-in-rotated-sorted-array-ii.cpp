class Solution {
public:
    bool bs(vector<int>& nums, int target , int s, int e){

        while(s<=e){
            int mid = s + (e-s)/2;

            if (nums[mid]== target){
                return true;
            }
            else if(nums[mid]< target){
                s=mid+1;

            }else{
                e=mid-1;
            }
        }
        return false;
    }

    int pivotIndex( vector<int>& nums, int n){
        // int n=nums.size();
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


    int search(vector<int>& nums, int target) {

        int n= nums.size();
        while(n>1 && nums[0] == nums[n-1]){
            n--;
        }
        cout<<n;

        int pivot_ind = pivotIndex(nums, n);
        cout<<pivot_ind;
        int ans=false;

        if(pivot_ind==-1){
            return false;
        }
        if (pivot_ind >= nums.size() - 1) {
            return bs(nums, target, 0, n - 1);
        }
        
        if (target>= nums[0] && target<=nums[pivot_ind]){
            ans=bs(nums, target, 0, pivot_ind);
        }else{
            ans=bs(nums, target, pivot_ind+1, nums.size()-1);
        }

        return ans;
        
    }
};