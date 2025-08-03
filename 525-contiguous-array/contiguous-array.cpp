class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum =0;
        // vector<int> index;
        unordered_map<int, int> totalSum;

        // index.push_back(0);
        int maxi = 0;
        totalSum[0] = -1;


        for(int i =0; i<nums.size(); i++){
            if(nums[i] == 0){
                sum -= 1;
            }
            else{
                sum += 1;
            }

            

            // if(nums[i] == 0){
                if(totalSum.find(sum ) != totalSum.end()){
                    maxi = max(maxi, i - totalSum[sum]);
                }
                else{
                    totalSum[sum] = i;
                }
            // }else
            
                // if(totalSum.find(sum  != totalSum.end()){
                //     maxi = max(maxi, i - totalSum[sum]);
                // }
            // }
        



        // for(int i =1; i<index.size(); i++){
        //     maxi = max (maxi, index[i] - index[i-1]);
        // }
        }
        return maxi;
        

    }
};