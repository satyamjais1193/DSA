class Solution {
public:
    vector<int> solve(vector<int>& nums){
        int n = nums.size();

        vector<int> lis(n, 1);
        vector<int>prnt(n, -1);

        int maxlis = 1;
        int index = 0;

        for(int i = 0; i<n; i++){
            for(int j = i -1; j>= 0; j--){

                if( lis[i] < 1 + lis[j]  && nums[i] % nums[j] == 0){
                    lis[i] = 1 + lis[j];
                    prnt[i] = j;
                }
            }
            if( lis[i] > maxlis){
                maxlis = lis[i];
                index = i;
            }
            // maxlis = max( maxlis, lis[i]);
        }
        
        vector<int> ans;

        while( index != -1){
            ans.push_back(nums[index]);
            index = prnt[index];
        }
        return ans;


    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return solve( nums);
    }
};