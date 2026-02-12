class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();

        // Prefix sum of travel
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + travel[i - 1];
        }

        int total = 0;
        int lastM = 0, lastP = 0, lastG = 0;

        for (int i = 0; i < n; i++) {
            for (char c : garbage[i]) {
                total++; // pickup time
                if (c == 'M') lastM = i;
                else if (c == 'P') lastP = i;
                else if (c == 'G') lastG = i;
            }
        }

        total += prefix[lastM];
        total += prefix[lastP];
        total += prefix[lastG];

        return total;
    }
};
