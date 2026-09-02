class Solution {
public:
    bool checkPalin(string s){
        int i=0;
        int j= s.size()-1;

        while(i<=j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int solve(string& s, vector< vector<int>> &dp, int i, int j){
        //base case 
        if(i > j) return 0;
        if(i == j) return 1;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        //ek case mai kerunga
        if(s[i] == s[j]){
            dp[i][j] = 2 + solve(s,dp , i+1, j-1);
        }
        else{
            dp[i][j] = max(solve(s,dp,i+1, j), solve(s,dp, i, j-1));
        }

        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        vector< vector<int> > dp(s.size(), vector<int>(s.size(), -1));
        return solve(s,dp, 0, s.size()-1);
        
    }
};