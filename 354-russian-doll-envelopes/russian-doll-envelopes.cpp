class Solution {
public:
    static bool comp(vector<int>a, vector<int>b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();

        sort(env.begin(), env.end(), comp);

        vector<int>temp;

        for(int i =0; i< n; i++){
            int index = lower_bound( temp.begin(), temp.end(), env[i][1]) - temp.begin();

            if(index == temp.size()){
                temp.push_back(env[i][1]);
            }
            else{
                temp[index] = env[i][1];
            }
        }

        return temp.size();
    }
};