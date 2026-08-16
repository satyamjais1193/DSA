class Solution {
public:
    double timetaken(vector<int>& dist, int speed){
        double time = 0.0;
        for(int i =0; i<dist.size() -1; i++){
            time += (int)(dist[i] + speed -1)/speed;
        }
        time += (double) dist[dist.size() -1]/ speed;
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        // if(hour < dist.size()) return -1;

        int ans = -1;
        int s = 1;
        int e= 10000000;

        while(s <= e){
            int mid = s +(e-s)/2;
            if(timetaken(dist, mid) <= hour){
                ans = mid;
                //reduce speed;
                e = mid -1;
            }
            else{
                s = mid +1;
            }
        }
        return ans;
    }
};