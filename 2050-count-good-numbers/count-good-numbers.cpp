class Solution {
public:
    static const long long MOD = 1e9 + 7;
    long long fastExpo(long long base, long long exp){
        long long result =1;
        while(exp > 0){
            if(exp & 1){
                result = (result * base) %MOD;
            }
            base = (base * base) % MOD;
            exp /=2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long result = 1;
        long long  even = (n+1)/2;
        long long odd  =  n/2;
        // for(long long i =0; i<n; i++){
        //     if(i&1)
        //         result = ((result%MOD) * ( 4%MOD) )% MOD;
        //     else
        //         result = ((result%MOD) * ( 5%MOD) )% MOD;
        // }

        return (fastExpo(5, even) * fastExpo(4, odd)) %  MOD;
        //  ans;
        
    }
};