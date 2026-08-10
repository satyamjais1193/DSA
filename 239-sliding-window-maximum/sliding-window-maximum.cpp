class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of elements in decreasing order of value
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            //removve 
            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            //additon
            // to add remove smaller dq enrty frist which are less then new elment... such that it maintain monotonic queue

            while(!dq.empty() && nums[ dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);

            //process ans 
            if(i >= k-1){
                res.push_back(nums[dq.front()]);
            }

        }
        return res;

        return res;
    }
};
