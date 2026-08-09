class Solution {
public:
    unordered_set<string> ans;

    void solve(string &s, int idx,
               int balance,
               int remOpen, int remClose,
               string path) {

        // invalid if more ')' than '('
        if (balance < 0) return;

        // end of string
        if (idx == s.size()) {
            if (balance == 0 && remOpen == 0 && remClose == 0) {
                ans.insert(path);
            }
            return;
        }

        char ch = s[idx];

        // remove '('
        if (ch == '(' && remOpen > 0) {
            solve(s, idx + 1, balance,
                  remOpen - 1, remClose, path);
        }

        // remove ')'
        if (ch == ')' && remClose > 0) {
            solve(s, idx + 1, balance,
                  remOpen, remClose - 1, path);
        }

        // keep character
        if (ch != '(' && ch != ')') {
            solve(s, idx + 1, balance,
                  remOpen, remClose, path + ch);
        }
        else if (ch == '(') {
            solve(s, idx + 1, balance + 1,
                  remOpen, remClose, path + ch);
        }
        else { // ch == ')'
            solve(s, idx + 1, balance - 1,
                  remOpen, remClose, path + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int remOpen = 0, remClose = 0;

        for (char ch : s) {
            if (ch == '(') remOpen++;
            else if (ch == ')') {
                if (remOpen > 0) remOpen--;
                else remClose++;
            }
        }

        solve(s, 0, 0, remOpen, remClose, "");

        return vector<string>(ans.begin(), ans.end());
    }
};