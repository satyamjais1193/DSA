class trie{
public:
    bool isend;
    trie* child[26];
    trie(){
        isend = false;
        for(int i = 0; i< 26; i++){
            child[i] = nullptr;
        }
    }
};

class WordDictionary {
public:
    //this is main concept -- store first node of dict in startnode.. so that you can traverse and update your trie using startnode- node;
    trie* startnode;
    WordDictionary() {
        startnode = new trie();
    }
    
    void addWord(string word) {
        trie* root = startnode;
        for( auto ch : word){
            int index = ch - 'a';
            if( root->child[index] == nullptr){
                root->child[index] = new trie();
            }
            root = root->child[index];
        }
        //common mistak-- mark as terminal when word end;
        root->isend = true;
    }

    bool ssolve(trie* root,  string& word, int pos){
        if(word.size() == pos) return root->isend;
        // cout<<word<<endl;
        
        int index= word[pos] - 'a';
        if(word[pos] == '.'){
            //to match every one aplha
            int found = false;
            for(int i =0; i< 26; i++){
                
                if(root->child[i] != nullptr){
                    found = found || ssolve(root->child[i], word, pos +1); 
                }
                
            }
            return found;
        }
        else{
            //a vaild alpha
            if(root->child[index] == nullptr){
                return false;
            }
            else{
                return ssolve(root->child[index], word, pos +1);
            }

        }
        return false;
    }
    
    bool search(string word) {
        //iterative solution will not work here...... as thier are multiple option for proceed when ch = '.'

        // trie* root = startnode;
        // for(auto ch : word){
        //     if(ch != '.'){
        //         int index = ch - 'a';
        //         if(root->child[index] == nullptr){
        //             return false;
        //         }
        //     }
        // }

        //recurive soltuion
        return ssolve(startnode, word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */ 