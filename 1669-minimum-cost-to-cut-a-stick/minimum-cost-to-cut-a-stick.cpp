class Solution {
public:
    // i denote starting point of rod,, and j ending points..  based on allowed cuts possible
    vector< vector< int>> dp;
    int solve( vector<int>& cuts, int i , int j){
        if(j - i == 1) return 0;

        int mini = 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        //k represent possible cut can be put-- as cut are predefined in cuts segment... 
        //as cuts are is sorted order -- k is used to serech the possible cuts in i to j lenth rods...

        int rodlen = cuts[j] - cuts[i];
        // int mini = 1e9;
        for(int k = i + 1; k<j; k++){
            int cost = rodlen + solve( cuts, i, k) + solve(cuts, k, j);
            mini = min( mini, cost );
        }
        return dp[i][j] =  mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.push_back(0);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        dp.assign( m , vector<int> ( m , -1) );
        return solve( cuts, 0 , m -1 );
    }
};