class Solution {
public:
    int hammingDistance(int x, int y) {
        string strx = bitset<32>(x).to_string();
        cout<<strx<<endl;


        string stry = bitset<32>(y).to_string();
        cout<<stry<<endl;
        int count = 0;
        for (int i =0 ; i < 32; i++){
            if(strx[i] -'0' != stry[i] -'0') count ++;
        }
        return count;

    }
};