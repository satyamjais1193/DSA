class Solution {
public:
    vector<int> asteroidCollision(vector<int>& astro) {
        stack<int> st;//move right
        vector<int> moveleft;

        for(int i = 0; i<astro.size() ; i++){

            while(!st.empty() && astro[i] < 0 && astro[st.top()] < abs( astro[i]) ){
                st.pop();
            }
            
            if(!st.empty() && astro[st.top()] == -1*(astro[i]) ){
                st.pop();
                continue;
            } 

            if(st.empty()){
                if(astro[i] < 0)
                    moveleft.push_back( i);
                // else
                //     st.push(i);
            }

            if(astro[i] > 0 ){
                st.push(i);
            }
        }

        vector<int> ans;
        vector<int> temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse( temp.begin(), temp.end());

        for(int ind : moveleft){
            ans.push_back(astro[ind]);
            cout<<astro[ind]<<" ";
        }
        cout<<endl;
        for(int ind : temp){
            ans.push_back(astro[ind]);
            cout<<astro[ind]<< " ";
        }
        return ans;


    }
};