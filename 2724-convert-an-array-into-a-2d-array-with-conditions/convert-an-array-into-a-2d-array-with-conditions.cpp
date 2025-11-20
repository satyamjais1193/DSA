class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0;
        for (int n : nums) {
            maxFreq = max(maxFreq, ++freq[n]);
        }

        // create maxFreq rows
        vector<vector<int>> ans(maxFreq);

        // distribute each distinct value across rows 0..freq-1
        for (auto &p : freq) {
            int val = p.first;
            int cnt = p.second;
            for (int i = 0; i < cnt; ++i) {
                ans[i].push_back(val);
            }
        }

        return ans;
    }
};
