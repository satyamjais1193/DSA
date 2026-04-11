class Solution {
public:
    int maxDistinct(string s) {
        vector<bool> freq(26, 0);
        int count = 0;
        for(auto ch : s){
            if(!freq[ch-'a']){
                count ++;
                freq[ch-'a'] = 1;
            }
        }
        return count;
    }
};