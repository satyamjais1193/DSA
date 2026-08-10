class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int ans = 0;
        int start  = 0; int end = 0;
        int n = nums.size();

        deque<int>maxi;//monotonic dque for max elemrnt in window
        deque<int>mini;

        while( end < n){
            //removal
            if(!maxi.empty() && end - maxi.front()  +1 > end - start + 1){
                maxi.pop_front();
            }
            if(!mini.empty() && end - mini.front()  +1 > end - start + 1){
                mini.pop_front();
            }

            //updating mini and maxi // addition
            while(!maxi.empty() && nums[maxi.back()] < nums[end]){
                maxi.pop_back();
            }
            maxi.push_back(end);

            while(!mini.empty() && nums[mini.back()] > nums[end]){
                mini.pop_back();
            }
            mini.push_back(end);

            int winlimit = nums[maxi.front()] - nums[mini.front()];
            if(winlimit <= limit){
                ans = max( end - start + 1, ans);
            }
            else{
                start ++;
            }
            end ++;







        }
        return ans;
        
    }
};