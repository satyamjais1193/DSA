class Solution {
public:
    vector<string> ans;
    
    void solve(int& n, int open, string temp ){
        if(temp.size() == 2* n ){
            if(open ==0)
                ans.push_back(temp);
            // cout<<temp<<" ";
            return ;
        }


        if(open<n){
            temp += '(';
            solve(n , open +1, temp);
            temp.pop_back();
        }

        if(open >0){
            temp += ')';
            solve(n, open -1, temp);
            temp.pop_back();
        }

    }


    vector<string> generateParenthesis(int n) {
        solve(n, 0, "");
        return ans;
    }
};