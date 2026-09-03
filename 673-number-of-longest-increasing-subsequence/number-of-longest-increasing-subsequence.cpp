class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxlis = 1;

        vector< int> lis(n, 1);
        vector<int> count(n, 1);

        for( int i = 0; i< n; i++){
            for(int j = 0; j< i; j++){

                if(nums[j]< nums[i]){
                    if( lis[i] < lis[j] +1){
                        lis[i] = lis[j] +1;
                        count[i] = count [j];
                    }
                    else if( lis[i] == lis[j] +1){
                        count[i] += count[j];
                    }
                }
            }
            maxlis = max( maxlis, lis[i]);
        }
        cout<< maxlis<<endl;
        for( int n : count){
            cout<<n << " ";
        }
        // return count[]
        int ans = 0;

        for(int i = 0; i<n; i++){
            if( lis[i] == maxlis){
                ans += count[i];
            }
        }
        return ans;
    }
};