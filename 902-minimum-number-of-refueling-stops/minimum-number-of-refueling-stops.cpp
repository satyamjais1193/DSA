class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int cantravel = startFuel;
        int index = 0;
        int count = 0;
        priority_queue<int> max_fule;

        while (cantravel < target) {
            // Add all reachable stations to max-heap
            while (index < stations.size() && cantravel >= stations[index][0]) {
                max_fule.push(stations[index][1]);
                index++;
            }

            if (max_fule.empty()) return -1;

            cantravel += max_fule.top();
            max_fule.pop();
            count++;
        }

        return count;
    }
};
