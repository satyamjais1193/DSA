class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int maxi = max(start, goal);

        while(maxi){
            int slsb = start&1;
            int glsb = goal&1;

            if(slsb ^ glsb == 1){
                count ++;
            }

            start = start >>1;
            goal = goal>>1;
            maxi = maxi >>1;
        }
        return count;
    }
};