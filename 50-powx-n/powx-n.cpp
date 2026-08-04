class Solution {
public:
    double myPow(double x, int n) {
        long long binaryform = n;
        if(n< 0){
            x = 1/x;
            binaryform = -binaryform;
        }
        double ans = 1;
        while( binaryform >0){
            if((binaryform &1) == 1){
                //when unit digit is one 
                ans *= x;

            }
            x = x*x;
            binaryform /= 2;
        }
        return ans;
    }
};