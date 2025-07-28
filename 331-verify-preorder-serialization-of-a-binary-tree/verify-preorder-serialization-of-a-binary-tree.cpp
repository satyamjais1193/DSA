class Solution {
public:
    bool solve (string& s ,int& index, bool l, bool r){
        // if(s[index] >= s.size()){

        //     if(l && r){
        //         return true;
        //     }
        //     else{
        //         return false;
        //     }
        // }

        if(index < s.size() && s[index] == '#') {
            index++;
            return true;
        }
        
        if(index < s.size() &&  s[index] == ','){
            index ++;
        }

        //processing n
        if(index < s.size() && s[index] != ','){
            index++;
            while(index < s.size() && s[index] != ','){
                index++;
            }
        }

        if(index < s.size() &&  s[index] == ','){
            index ++;
        }

        //left call
        bool left = false;
        if(index < s.size() ){
            left =solve(s, index, true, false);
        }

        if(index < s.size() &&  s[index] == ','){
            index ++;
        }

        //right call
        bool right = false;
        if(index< s.size() ){
            right = solve(s, index, true, true);
        }

        if(index < s.size() &&  s[index] == ','){
            index ++;
        }
        

        return left&&right;

    }
    bool isValidSerialization(string preorder) {
        int index =0;
        
        bool ans = solve(preorder, index, false, false);

        if(index >= preorder.size()){
            return ans;
        }
        else{
            return false;
        }
        
    }
};