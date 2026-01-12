class Solution {
public:
    bool isValidSpeed ( vector<int> &piles, int h, int k ){
        double hours =0;
        for (auto b : piles){
            hours += ceil((double)b / k);
        }
        if(hours <= h) return true;
        else return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        // return maxPile;
        int ans =-1;

        int s =1; 
        int e = maxPile;

        while(s <= e){
            int mid = s +(e-s)/2;
            if(isValidSpeed(piles,h, mid)){
                //valid spped
                ans = mid;
                e = mid -1;
            }
            else{
                //not valid spped , thus increase speed
                s = mid +1;
            }

            
        }
        return ans;


    }
};