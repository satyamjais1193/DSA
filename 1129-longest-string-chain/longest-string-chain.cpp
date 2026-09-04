class Solution {
public:
    static bool comp(string a , string b){
        return a.size() < b.size();
    }

    bool ispred( string& curr, string& prev){
        if(curr.size() != prev.size() +1) return false;

        for( int i =0 ; i < curr.size() ; i++){
            string newcurr = curr.substr(0, i) + curr.substr(i +1);
            if(newcurr == prev) return true;
        }
        return false;
    }


    int longestStrChain(vector<string>& words) {
        sort( words.begin(), words.end(), comp);

        int n = words.size();
        vector<int> lis( n, 1);
        int maxlis = 1;

        for( int i = 0; i< n; i++){
            for( int j = 0;  j < i ; j++){
                if(lis[i] < 1 + lis[j] && ispred(words[i] , words[j]) ){
                    lis[i] = 1 + lis[j];
                }
            }
            maxlis = max( maxlis, lis[i]);
        }
        return maxlis;
    }

};