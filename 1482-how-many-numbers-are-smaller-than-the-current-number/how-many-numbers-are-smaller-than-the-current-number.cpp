

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int count[101] = {0};
        for (int num : nums) count[num]++; // Count frequencies
        
        // Prefix sum: count[i] now stores total elements <= i
        for (int i = 1; i <= 100; i++) {
            count[i] += count[i - 1];
        }
        
        vector<int> result;
        for (int num : nums) {
            // For each num, elements smaller than it are at count[num-1]
            if (num == 0) result.push_back(0);
            else result.push_back(count[num - 1]);
        }
        return result;
    }
};
