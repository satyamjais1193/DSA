class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;
        vector<int> ans;
        priority_queue<pair<int,int>>max_heap;

        for(int n :nums){
            freq[n]++;
        }

        for(auto entry : freq){
            pair<int, int> p;
            p.first = entry.second;//freq
            p.second = entry.first;//elements

            max_heap.push(p);
        }

        for(int i =0; i<k; i++){
            pair<int, int> p = max_heap.top();
            max_heap.pop();
            ans.push_back(p.second);
        }

        return ans;
    }
};