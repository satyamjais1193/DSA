class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;

        for (string& query : queries) {
            int i = 0, j = 0;
            bool match = true;

            while (i < query.size() && j < pattern.size()) {
                if (query[i] == pattern[j]) {
                    i++;
                    j++;
                } else if (islower(query[i])) {
                    i++;
                } else {
                    match = false;
                    break;
                }
            }

            // After pattern is fully matched, rest of query should only have lowercase
            while (i < query.size()) {
                if (isupper(query[i])) {
                    match = false;
                    break;
                }
                i++;
            }

            // Final check: did we match full pattern?
            result.push_back(match && j == pattern.size());
        }

        return result;
    }
};
