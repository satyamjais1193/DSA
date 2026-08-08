class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    //     if(nums.size() == 0) return 0;
    //     if(nums.size() ==1) return 1;
        unordered_set< int> st(nums.begin(), nums.end());

        int ans = 0;
        
        //iterate on set,,not on nums
        for(int n : st){
            // vis[n] = true;

            //start only if prev element is not found
            if(st.find(n-1) == st.end()){
                int count = 0;
                int nextn = n;

                while(st.find(nextn) !=st.end() ){
                    count ++;
                    nextn = nextn +1;
                }
                ans = max(ans, count);

            }
        }
        return  ans;
        
    }
};