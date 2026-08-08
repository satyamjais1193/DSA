class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long  xorval = 0;
        for(int n : nums){
            xorval = xorval ^ n;
        }
        // mask for first set bit of xor value recibved
        long long mask = (xorval & (-xorval));

        long long grpa = 0;
        long long grpb =0;

        for(int n : nums){
            if(n & mask){
                grpa ^= n;
            }
            else{
                grpb^=n;
            }
        }

        return {(int)grpa, (int)grpb};
    }
};