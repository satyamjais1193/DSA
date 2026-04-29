class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> unique_num; //ecxulding number formed by zeros
        vector<int> ans;
        ans.push_back(1);
        unique_num.push_back(1);
        int digit =9;
        int multi=1;
        for(int i =1; i<= n; i++){
            multi *= digit;
            unique_num.push_back(multi);
            int zero_num = unique_num[i-1] * (i-1);
            // cout<<zero_num<< " ";
            int final_ans = zero_num + multi + ans[i-1];
            // cout<<final_ans<<endl;
            ans.push_back(final_ans);
            digit --;
        }

        return ans[n];
    }
};