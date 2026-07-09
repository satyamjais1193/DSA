class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
            vector<int> set(graph.size(), -1);
            int color = 0;

        for(int start = 0; start < graph.size(); start ++){
            if(set[start] != -1) continue;

            set[start] = color %2;
            queue<int> q;
            q.push(start);

            while(!q.empty()){
                color ++;
                int n = q.size();
                for(int i= 0; i<n ; i++){
                    int node = q.front(); q.pop();
                    

                    for(auto nbr : graph[node]){
                        if( set[nbr] == -1){
                            set[nbr] = color % 2;
                            q.push(nbr);
                        }
                        else{
                            //visited
                            if(set[nbr] == set[node]){
                                return false;
                            }
                        }
                    }
                }
                //not visited
                
            }
        }
        // for(auto color : set) {
        //     if(color == -1) return false;
        // }
        return true;
    }
};