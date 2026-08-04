class Solution {
public:
    set<string> ans;
    void build(int& n , string temp,char prev ){
        if(temp.size() == n){
            ans.insert(temp);
            
            return;
        }

        if(prev == '0'){
            temp += '1';
            build(n, temp, '1');
        }
        else{
            temp += '0';
            build(n, temp, '0');
            temp.pop_back();
            temp += '1';
            build(n, temp, '1');
        }

    }
    vector<string> validStrings(int n) {
        string temp = "";
        build(n, temp, '0');
        build(n, temp, '1');
        return vector<string>(ans.begin(), ans.end());
    }
};