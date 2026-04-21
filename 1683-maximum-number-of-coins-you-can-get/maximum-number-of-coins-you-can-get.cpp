class Solution {
public:
    int maxCoins(vector<int>& piles) {
        std::sort(piles.begin(), piles.end());
        
        int totalCoins = 0;
        int n = piles.size() / 3;
        
        // Start from the second-to-last element
        // Move backwards, skipping one element each time (which Alice takes)
        // Stop once we have picked n piles for ourselves
        for (int i = piles.size() - 2; n > 0; i -= 2) {
            totalCoins += piles[i];
            n--;
        }
        
        return totalCoins;
    }
};