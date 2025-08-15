class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // stores indices of elements in decreasing order of value
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove elements smaller than current from the back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 2. Push current index
            dq.push_back(i);

            // 3. Remove front if it's outside the window
            if (dq.front() <= i - k) {
                dq.pop_front();
            }

            // 4. Store max when window size is reached
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
