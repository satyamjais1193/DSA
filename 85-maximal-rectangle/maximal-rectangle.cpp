class Solution {
public:
    int maxi = 0;

    pair<int, int> solve(vector<vector<char>>& mat, int x, int y, vector<vector<pair<int, int>>>& dp) {
        // Base case
        if (x >= mat.size() || y >= mat[0].size()) {
            return {0, 0};
        }

        if (dp[x][y].first != -1) return dp[x][y];

        pair<int, int> right = solve(mat, x, y + 1, dp);
        pair<int, int> down = solve(mat, x + 1, y, dp);

        if (mat[x][y] == '1') {
            int hor = right.first + 1;
            int ver = down.second + 1;

            dp[x][y] = {hor, ver};

            // Try to build rectangles down from this point
            int minWidth = hor;
            for (int k = 0; k < ver; ++k) {
                minWidth = min(minWidth, dp[x + k][y].first);
                int area = minWidth * (k + 1);
                maxi = max(maxi, area);
            }
        } else {
            dp[x][y] = {0, 0};
        }

        return dp[x][y];
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<vector<pair<int, int>>> dp(rows, vector<pair<int, int>>(cols, {-1, -1}));

        // for (int i = 0; i < rows; ++i)
        //     for (int j = 0; j < cols; ++j)
        pair<int,int> waste = solve(matrix, 0, 0, dp);

        return maxi;
    }
};
