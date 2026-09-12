class Solution {
public:
    bool canship(vector<int>& w, int& days, long long maxw){
        int reqday = 0;
        int i = 0; 
        while( i < w.size()){
            long long  sum = 0;
            while(i < w.size() && sum + w[i] <= maxw){
                sum += w[i];
                i++;
            }
            reqday ++;
        }
        return reqday <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        // sort

        long long sum = 0;
        for(int w : weights){
            sum +=w;
        }

        //this is common error---- when you not start with s = max_element.
        long long s= *max_element(weights.begin(), weights.end());
        
        long long  e = sum ;
        long long ans = 0;

        while(s<=e){
            long long mid = s + ( e-s)/2;

            if(canship(weights, days, mid)){
                ans = mid;
                // s = mid +1;
                e = mid -1;
            }
            else{
                // e = mid -1;
                s  = mid +1;
            }
        }
        return ans;

    }
};