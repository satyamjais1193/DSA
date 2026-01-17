class Solution {
public:
    bool rotateString(string s, string goal) {
        string news = s;

        for(char ch : s){
            news.erase(0,1); 
            news += ch;
            if (news == goal) return true;
        }
        return false;
    }
};