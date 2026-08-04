class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost = 0;
        for(int n : cost) totalcost += n;

        int tgas = 0;
        for(int n : gas) tgas += n;

        if(totalcost > tgas) return -1;

        // int i =0;
        int start = 0;
        int currgas = 0;
        for(int i =0; i<gas.size(); i++){
            currgas += gas[i] - cost[i];
            if(currgas< 0 ){
                start = i+1;
                currgas = 0;
            }

        }
        return start;

    }
};