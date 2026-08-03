class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string& s, int ind, int open){
        //base case abhi 
        if(ind >= s.size()){
            if(open == 0){
                return true;
            }
            else{
                return false;
            }
        }
        if(dp[ind][open] != -1) return dp[ind][open];

        bool ans = false;

            if(s[ind] == '(' ){
                ans = solve(s, ind +1, open +1);
            }
            else if(s[ind] == ')' ){
                if(open == 0) 
                    return dp[ind][open] = false;
                else
                    ans = solve(s, ind +1, open -1);
            } 
            else{

                ans = ans || solve( s, ind +1, open);

                ans = ans || solve( s, ind +1, open +1);

                if(open >0)
                    ans = ans || solve( s, ind +1, open -1);

            }

        return  dp[ind][open] = ans;

    }
    bool checkValidString(string s) {
        // stack<char> st;
        dp.assign(s.size() +1, vector<int>(s.size() +1, -1));
        return solve(s, 0, 0);
    }
};