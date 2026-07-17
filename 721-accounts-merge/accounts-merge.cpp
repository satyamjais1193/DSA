class Solution {
public:
    vector<int> parent, rank;

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv) return;

        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        unordered_map<string, int> emailToAccount;

        // Step 1: Union accounts having common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {

                string email = accounts[i][j];

                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    unionByRank(i, emailToAccount[email]);
                }
            }
        }

        // Step 2: Collect emails according to parent
        unordered_map<int, vector<string>> mergedEmails;

        for (auto &it : emailToAccount) {
            string email = it.first;
            int account = it.second;

            int p = findParent(account);

            mergedEmails[p].push_back(email);
        }

        // Step 3: Prepare answer
        vector<vector<string>> ans;

        for (auto &it : mergedEmails) {

            int account = it.first;
            vector<string> emails = it.second;

            sort(emails.begin(), emails.end());

            vector<string> temp;
            temp.push_back(accounts[account][0]);

            for (auto &email : emails)
                temp.push_back(email);

            ans.push_back(temp);
        }

        return ans;
    }
};