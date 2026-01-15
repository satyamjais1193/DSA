class Solution {
public:
    bool canShift(vector<int>& weights, int allowedw, int days){
        int wsum = 0;
        int count = 1;

        for(int w : weights){
            if(wsum + w <= allowedw){
                wsum += w;
            }
            else{
                count ++;
                wsum = w;
            }
        }
        cout<<allowedw <<" "<<count <<endl;

        return (count <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0, ans =-1,  maxi = -1 ;
        for(int w : weights){
            maxi = max(maxi, w);
            sum += w;
        }

        int s = maxi;
        int e = sum;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if( canShift ( weights, mid, days)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid +1;
            }
        }
        return ans;
    }
};