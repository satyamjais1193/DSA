class Solution {
public:

    int maxProduct(vector<int>& nums) {
        int minprefix  = 1;
        int maxprefix = 1;
        int ans =INT_MIN;

        for(auto n : nums){
            if(n < 0){
                swap(minprefix, maxprefix);
            }

            minprefix = min( n, minprefix*n);
            maxprefix = max(n, maxprefix*n);
            ans = max( ans, maxprefix);

        }
        return ans;
    }
};