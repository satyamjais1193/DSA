#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // Map to store elements of each diagonal
        // Key: row - col
        unordered_map<int, vector<int>> diagonals;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                diagonals[i - j].push_back(grid[i][j]);
            }
        }

        // Sort each diagonal based on the row-col key
        for (auto& [diff, values] : diagonals) {
            if (diff >= 0) {
                // Bottom-left: Non-increasing (Descending)
                sort(values.begin(), values.end(), greater<int>());
            } else {
                // Top-right: Non-decreasing (Ascending)
                sort(values.begin(), values.end());
            }
        }

        // Put sorted values back into the grid
        // We use a separate index map to keep track of which element to pick next
        unordered_map<int, int> indexMap;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int diff = i - j;
                grid[i][j] = diagonals[diff][indexMap[diff]++];
            }
        }

        return grid;
    }
};
