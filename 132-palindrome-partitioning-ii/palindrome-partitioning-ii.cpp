class Solution {
public:

    //this code is froms palindeorm e partitioning
    
    vector< vector<int>> palindrome;
    int solve(string& s, int i , int j){
        if(i>= j) return 1;

        if (palindrome[i][j] != -1) return palindrome[i][j];

        if(s[i] == s[j]){
            return palindrome[i][j] = solve(s, i+1, j-1);
        }
        else{
            return palindrome[i][j] = 0;
        }
    }
    int countSubstrings(string& s) {
        int n = s.size();
        palindrome.assign(n, vector<int>(n, -1));

        int count = 0;

        for(int i =0; i< n; i++){
            for(int j= i; j<n; j++){
                if(solve(s, i ,j)){
                    count ++;
                }
            }
        }
        return count;
        
    }


    //this is main logic--- fo cut
    vector<int>dp;
    int solve(string& s, int i){
        
        if(i >= s.size() ) return -1;

        if(dp[i] != -1) return dp[i];
        int n = s.size();


        int ans = INT_MAX;
        for(int j = i; j< n ; j++){
            if(palindrome[i][j]){
                int cut = 1 + solve(s, j +1);   
                ans = min( cut, ans);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int tmp = countSubstrings(s);
        dp.assign(s.size(), -1);

        return solve(s, 0);
    }
};