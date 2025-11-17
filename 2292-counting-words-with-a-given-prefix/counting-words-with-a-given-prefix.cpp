class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (auto &w : words) {
            if (w.rfind(pref, 0) == 0)   // checks if pref starts at index 0
                count++;
        }
        return count;
    }
};
