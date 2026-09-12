class trie{
public: 
    bool isend;
    trie* child[2];

    trie(){
        isend = false;
        child[0] = nullptr;
        child[1] = nullptr;
    }
};

class Solution {
public:
    trie* startnode;

    void insertnum(int num){
        // int temp = num;
        trie* root = startnode;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(root->child[bit] == nullptr){
                root->child[bit] = new trie();
            }
            root = root->child[bit];
        }
    }

    int getmaxxor(int num){
        trie* root = startnode;
        int maxxor = 0;
        for(int i = 31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(root->child[1-bit] != nullptr){
                //opposite bit exist
                maxxor = (maxxor<<1) | (1);
                root = root->child[1-bit];

            }
            else{
                maxxor = (maxxor<<1) | (0);
                root= root->child[bit];
            }
            // root = root->child[]

        }
        return maxxor;

    }



    int findMaximumXOR(vector<int>& nums) {
        startnode = new trie();

        for(auto& n : nums) insertnum(n);

        int maxi = 0;
        for(auto& n : nums){
            maxi = max(maxi, getmaxxor(n));
        }
        return maxi;
    }
};