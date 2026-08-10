class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        bool sign = true;

        if (dividend >= 0 && divisor < 0)
            sign = false;
        else if (dividend < 0 && divisor > 0)
            sign = false;

        // changed long -> long long
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        // changed long -> long long
        long long quotient = 0;

        while (n >= d) {
            int cnt = 0;

            while (n >= (d << (cnt + 1))) {
                cnt += 1;
            }

            // changed 1 -> 1LL
            quotient += 1LL << cnt;
            n -= (d << cnt);
        }

        // changed 1L -> 1LL
        if (quotient == (1LL << 31) && sign)
            return INT_MAX;

        if (quotient == (1LL << 31) && !sign)
            return INT_MIN;

        return sign ? (int)quotient : (int)(-quotient);
    }
};