class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second; 
            return a.first < b.first; 
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> max_heap(cmp);
        
        unordered_map<string, int> freq;
        vector<string> ans;
        for(auto key : words){
            freq[key] ++;
        }

        for(auto entry : freq){
            max_heap.push(make_pair(entry.second, entry.first));

        }
        for(int i =0; i<k ; i++){
            string top = max_heap.top().second;
            max_heap.pop();
            ans.push_back(top);
        }
        return ans;
        
    }
};