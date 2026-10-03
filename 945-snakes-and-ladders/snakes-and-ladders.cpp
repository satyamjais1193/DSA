class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        // Each square is represented using 0-based indexing:
        // square 1  -> index 0
        // square 2  -> index 1
        // ...
        // square n*n -> index n*n - 1
        vector<bool> vis(n * n, false);

        queue<int> q;

        // We start from square 1 -> index 0
        q.push(0);
        vis[0] = true;

        // Number of dice rolls made so far
        int timer = 0;

        while (!q.empty()) {

            // All nodes currently in the queue are reachable
            // using exactly 'timer' dice rolls.
            int size = q.size();

            for (int i = 0; i < size; i++) {

                int pos = q.front();
                q.pop();

                // Try all possible dice outcomes: 1, 2, 3, 4, 5, 6
                for (int nbr = pos + 1;
                     nbr <= min(pos + 6, n * n - 1);
                     nbr++) {

                    /*
                        Convert 1D square number 'nbr'
                        into board coordinates (row, col).

                        IMPORTANT:
                        nbr is already 0-based.

                        Example for n = 3:

                            7 8 9
                            6 5 4
                            1 2 3

                        0-based indices:

                            6 7 8
                            5 4 3
                            0 1 2
                    */

                    // Which row from the BOTTOM?
                    int level = nbr / n;

                    // Actual matrix row.
                    // Matrix row 0 is at the TOP,
                    // so we reverse it.
                    int row = n - 1 - level;

                    /*
                        Determine column.

                        level = 0 → bottom row → left to right
                        level = 1 → next row  → right to left
                        level = 2 → next row  → left to right
                        ...

                        Therefore:
                        even level → normal direction
                        odd level  → reversed direction
                    */
                    int col;

                    if (level % 2 == 0) {
                        col = nbr % n;
                    }
                    else {
                        col = n - 1 - nbr % n;
                    }

                    /*
                        'nbr' = square where the dice initially lands.

                        But if there is a snake/ladder,
                        the ACTUAL position becomes its destination.

                        So create 'next' to represent the
                        actual BFS state after applying snake/ladder.
                    */
                    int next = nbr;

                    if (board[row][col] != -1) {

                        // Snake or ladder exists.
                        // Board uses 1-based numbering,
                        // so convert it back to 0-based.
                        next = board[row][col] - 1;
                    }

                    // If after applying snake/ladder we reach
                    // the final square, this is our answer.
                    if (next == n * n - 1) {
                        return timer + 1;
                    }

                    /*
                        IMPORTANT:
                        We must mark 'next' visited,
                        NOT 'nbr'.

                        Why?

                        Suppose:

                            nbr = 2
                            2 → ladder → 15

                        Our actual BFS position is 15.

                        Therefore:

                            vis[15] = true  ✅

                        NOT:

                            vis[2] = true   ❌
                    */
                    if (!vis[next]) {

                        vis[next] = true;
                        q.push(next);
                    }
                }
            }

            // We have finished one BFS level.
            // Therefore, one dice roll has been used.
            timer++;
        }

        // Queue became empty without reaching n*n.
        // Therefore, destination is impossible.
        return -1;
    }
};