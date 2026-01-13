class Solution {
public:
    bool canMake(vector<int>& bloomDay,int wday, int m, int k){
        int count =0;
        int flower =0;

        for(auto bday : bloomDay){
            if(bday <= wday){
                flower ++;
                if(flower == k){
                    flower = 0;
                    count ++; 
                } 
            }
            else{
                flower =0;
            }
        }
        cout<<wday <<" "<<count<<endl;
        return (count >= m) ? true: false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int maxi = *max_element (bloomDay.begin(), bloomDay.end());
        if(bloomDay.size() <(long) m*k) return -1;

        int s =1;
        int e = maxi;
        int ans = -1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(canMake(bloomDay, mid, m, k)){
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