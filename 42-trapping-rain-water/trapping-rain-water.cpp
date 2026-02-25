class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nextg(n);
        stack<int>st;
        int maxi = 0;
        for(int i =0; i<n; i++){
            // while(!st.empty() && st.top()<= height[i]){
            //     st.pop();
            // }
            // if(st.empty()){
            //     nextg[i] = 0;
            // }
            // else{
            //     nextg[i] = st.top();
            // }
            // if(st.empty() ){
            //     st.push(height[i]);
            // }
            maxi = max(maxi , height[i]);
            if(maxi == height[i]){
                nextg[i] = 0;
            }
            else{
                nextg[i] = maxi;
            }
            
        }

        while(!st.empty()){
            st.pop();
        }
        for(int n : nextg){
            cout<<n<<" ";
        }
        cout<<endl;
        maxi =0;
        vector<int> prevg(n);
        for(int i =n-1; i>=0; i--){
            // while(!st.empty() && st.top()<= height[i]){
            //     st.pop();
            // }
            // if(st.empty()){
            //     prevg[i] = 0;
            // }
            // else{
            //     prevg[i] = st.top();
            // }

            // st.push(height[i]);
            maxi = max(maxi , height[i]);
            if(maxi == height[i]){
                prevg[i] = 0;
            }
            else{
                prevg[i] = maxi;
            }            
        }
        for(int n : prevg){
            cout<<n<<" ";
        }
        cout<<endl;
        int ans = 0;
        for(int i =0; i<n; i++){
            if(min(nextg[i] , prevg[i]) != 0){
                ans += min(nextg[i] , prevg[i]) - height[i];
            }
        }

        return ans;
    }


};