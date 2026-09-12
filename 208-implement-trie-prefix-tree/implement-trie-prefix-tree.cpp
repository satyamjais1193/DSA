class Trie {
public:
    char val;
    vector< Trie*> nextchar;
    bool isend;
    int countchar;

    Trie() {
        this->val = '_';
        for(int i = 0; i< 26; i++){
            this->nextchar.push_back(nullptr);
        }
        this->isend = false;
        this->countchar = 0;
        
    }

    Trie(char ch) {
        this->val = ch;
        for(int i = 0; i< 26; i++){
            this->nextchar.push_back(nullptr);
        }
        this->isend = false;
        this->countchar = 0;
        
    }
    void insertsolve(Trie* root, string word){
        if(word.size() == 0){
            root->isend = true;
            return;
        }

        char nextval = word[0];
        if(root->nextchar[nextval-'a'] == nullptr){
            //nextval is not present
            Trie* nextroot = new Trie(nextval);
            root->nextchar[nextval-'a'] = nextroot;
            insertsolve( nextroot, word.substr(1));
        }
        else{
            //already present -> just travel
            insertsolve( root->nextchar[nextval - 'a'], word.substr(1));
        }
    }
    
    void insert(string word) {
        insertsolve(this, word);
        
    }

    bool ssolve(Trie* root, string word){
        if( word.size() == 0) return root->isend;

        char nextval = word[0];
        if(root->nextchar[nextval-'a'] == nullptr){
            //nextval is not present
            return false;
        }
        else{
            //already present -> just travel
            return  ssolve( root->nextchar[nextval-'a'], word.substr(1));
        }
        return false;
    }
    
    bool search(string word) {
        return ssolve(this, word);
    }

    bool withsolve(Trie* root, string word){
        if( word.size() == 0) return true;

        char nextval = word[0];
        if(root->nextchar[nextval-'a'] == nullptr){
            //nextval is not present
            return false;
        }
        else{
            //already present -> just travel
             return withsolve( root->nextchar[nextval-'a'], word.substr(1));
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        return withsolve(this,  prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */