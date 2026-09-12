class trie {
public:
    bool isend;
    trie* child[26];

    trie() {
        isend = false;

        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};

class Solution {
public:
    trie* startnode;

    void addword(string& word) {

        trie* root = startnode;

        for (char ch : word) {

            int index = ch - 'a';

            if (root->child[index] == nullptr) {
                root->child[index] = new trie();
            }

            root = root->child[index];
        }

        root->isend = true;
    }

    void dfs(vector<vector<char>>& board, int& n, int& m, trie* root, int x,
             int y, string& word, vector<string>& ans) {

        // =====================================================
        // CORRECTION 1:
        // Move Trie pointer to CURRENT board character
        // =====================================================

        int index = board[x][y] - 'a';

        root = root->child[index];

        // =====================================================
        // Add current character to word
        // =====================================================

        char value = board[x][y];

        word += value;

        // Mark current cell as visited
        board[x][y] = '#';

        // =====================================================
        // CORRECTION 2:
        // Now root represents CURRENT character
        // =====================================================

        if (root->isend) {

            ans.push_back(word);

            // Prevent duplicate word
            root->isend = false;
        }

        // =====================================================
        // Explore 4 directions
        // =====================================================

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {

            int nx = x + dx[i];
            int ny = y + dy[i];

            // =================================================
            // CORRECTION 3:
            // Check neighbor exists in Trie BEFORE recursion
            // =================================================

            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                board[nx][ny] != '#') {

                int nextIndex = board[nx][ny] - 'a';

                if (root->child[nextIndex] != nullptr) {

                    dfs(board, n, m, root, nx, ny, word, ans);
                }
            }
        }

        // =====================================================
        // Backtracking
        // =====================================================

        word.pop_back();

        board[x][y] = value;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        startnode = new trie();

        // Build Trie
        for (auto& w : words) {
            addword(w);
        }

        int n = board.size();
        int m = board[0].size();

        vector<string> ans;

        string word = "";

        // =====================================================
        // Start DFS from every possible first character
        // =====================================================

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                int index = board[i][j] - 'a';

                // =================================================
                // CORRECTION 4:
                // Only start if first character exists in Trie
                // =================================================

                if (startnode->child[index] != nullptr) {

                    dfs(board, n, m, startnode, i, j, word, ans);
                }
            }
        }

        return ans;
    }
};