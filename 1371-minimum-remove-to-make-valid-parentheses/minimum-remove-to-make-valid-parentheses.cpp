class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<pair<char,int>> st;
        int ind =0;
        for(char ch : s){
            if(ch >= 'a' && ch<= 'z'){
                ind ++;
                continue;
            } 

            if(st.empty()){
                st.push({ch, ind});
            }
            else{
                if(ch == ')' && st.top().first == '('){
                    st.pop();
                }
                else{
                    st.push({ch, ind});
                }
            }
            ind ++;
        }

        unordered_set<int> invalid;
        while(!st.empty()){
            invalid.insert(st.top().second);
            st.pop();
        }

        for(int i =0 ;i<s.size(); i++){
            if(invalid.find(i) == invalid.end()){
                ans += s[i];
            }
        }
        return ans;
    }
};