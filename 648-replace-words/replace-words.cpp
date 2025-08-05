class Trie {
public:
    Trie* children[26];
    char val;
    bool isTerminal;

    Trie(char val) {
        this->val = val;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        this->isTerminal = false;
    }
};

class Solution {
public:
    void createTrie(Trie* root, string& word, int i) {
        // base case
        if (i >= word.size()) {
            root->isTerminal = true;
            return;
        }

        char child_ch = word[i];
        int child_ind = child_ch - 'a';
        Trie* child_node;

        if (root->children[child_ind] != nullptr) {
            // char alredy present
            child_node = root->children[child_ind];
        } else {
            // crete new node
            child_node = new Trie(child_ch);
            root->children[child_ind] = child_node;
        }

        createTrie(child_node, word, i + 1);
    }
    bool isDerivative(Trie* root, string& word, int i, string& prefix){
        if(root->isTerminal == true){
            return true;
        }
        if(i >= word.size()){
            return false;
        }

        char child_ch = word[i];
        int child_ind = child_ch - 'a';
        Trie* child_node;

        bool ans = false;
        if (root->children[child_ind] != nullptr) {
            // char alredy present
            prefix.push_back(child_ch);
            child_node = root->children[child_ind];
            ans= isDerivative(child_node, word, i+1, prefix);
        } else {
            ans= false;
        }
        return ans;

    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        // create trei
        Trie* root = new Trie(-1);

        for (auto s : dictionary) {
            createTrie(root, s, 0);
        }

        //search derivaltive and replace it;
        string result = "";
        int i =0;
        while(i<sentence.size()){
            int start = i;
            while(i<sentence.size() && sentence[i] != ' '){
                i++;
            }
            string word = sentence.substr(start, i- start);
            string prefix = "";

            if (isDerivative(root, word, 0, prefix)) {
                result += prefix;
            } else {
                result += word;
            }

            if (i < sentence.size()) {
                result += " ";
                i++;  // skip the space
            }
        }
        return result;

    }
};