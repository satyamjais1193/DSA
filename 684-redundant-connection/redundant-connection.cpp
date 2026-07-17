class Solution {
public:
    vector<int> prnt;
    vector<int> rank;
    int findprnt(int u){
        if(prnt[u] == u) return u;
        return prnt[u] = findprnt(prnt[u]);
    }

    void unionbyrank(int u, int v){
        int pu = findprnt(u);
        int pv = findprnt(v);

        if(pu == pv ) return;
        
        if(rank[pu] < rank[pv]){
            prnt[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            prnt[pv] = pu;
        }
        else{
            prnt[pu] = pv;
            rank[pv] ++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        prnt.resize(n+1);
        rank.assign(n+1, 0);

        // vector<bool> istaken(n+1, false);

        for(int i =1; i< n+1; i++){
            prnt[i] = i;
        }
        int x = -1; int y = -1;
        for(int i =0 ; i< n; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            if((findprnt(u) != findprnt(v))){
                // istaken[u]
                unionbyrank(u, v);
            }
            else{
                x = edges[i][0];
                y =edges[i][1];
            }


        }
        return {x, y};

        
    }
};