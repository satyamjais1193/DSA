class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi = -1;
        vector<int>ans (arr);
        for(int i =arr.size() -1 ; i>= 0; i--){
            ans[i] = maxi;
            maxi = max(maxi, arr[i]);
        }
        return ans;
    }
};