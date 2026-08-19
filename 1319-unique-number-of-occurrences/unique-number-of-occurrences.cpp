class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        unordered_set<int> seen;

        for (auto it : freq) {
            int count = it.second;

            if (seen.count(count)) {
                return false;
            }

            seen.insert(count);
        }

        return true;
    }
};