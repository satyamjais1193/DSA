class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastocc(26, -1);
        vector<bool> taken(26, false);

        for(int i =0; i<s.size(); i++){
            lastocc[s[i] - 'a'] = i;
        }

        stack<char> st;
        string ans = "";

        for(int i=0; i<s.size(); i++){
            if(taken[s[i]- 'a']) continue;

            while(!st.empty() && lastocc[st.top() - 'a'] > i && st.top() >= s[i]){
                taken[st.top() - 'a'] = false;
                st.pop();

            }

            taken[s[i] - 'a'] = true;
            st.push(s[i]);

        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};