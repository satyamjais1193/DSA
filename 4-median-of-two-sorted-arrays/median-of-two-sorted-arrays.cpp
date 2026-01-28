class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2, nums1);

        int low =0, high = n1; // for applying bs on range of number of elemenst can be taken from nums1,to make half sorted  of full merged sorted array 
        int left = (n1 +n2 +1 )/2; // number of elemtens in half sorted array
        int n = n1 +n2;
        while(low <= high){
            int mid1 = (low + high) /2;//number of elments in half sorted array from nums1
            int mid2 = left - mid1;// baki nums2 se hoga

            int l1 = (mid1 > 0) ? nums1[mid1-1] : INT_MIN;
            int l2 = (mid2 > 0) ? nums2[mid2-1] : INT_MIN;
            int r1 = (mid1 < n1) ?nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1){
                //correct division
                if(n&1){
                    //odd numbers of total elements
                    return max(l1, l2);
                }
                else{
                    //even numbers
                    return ((double) max(l1, l2) + min (r2 ,r1) ) /2.0;
                }
            }
            else if(l1>r2){
                //left most of nums1 is greater, thus remove it 
                high = mid1 -1;
            }
            else{
                // l2>r1--
                low = mid1 + 1;
            }
        }
        return 0;
        
    }
};