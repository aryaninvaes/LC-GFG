// this is technically bruteforce using bfs traversal for every node;
// we can use dsu to connect 
class Solution {
public:
    int m, n;

    vector<vector<int>> directions{
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    bool isSafe(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int bfs(int i, int j,
            vector<vector<bool>>& visited,
            vector<vector<int>>& grid) {

        visited[i][j] = true;

        queue<pair<int, int>> q;
        q.push({i, j});

        int sum = grid[i][j];

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();  

            for (auto& dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (isSafe(x_, y_) &&
                    !visited[x_][y_] &&
                    grid[x_][y_] > 0) {

                    visited[x_][y_] = true;
                    sum += grid[x_][y_];

                    q.push({x_, y_});
                }
            }
        }

        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 0 && !visited[i][j]) {
                    count = max(count, bfs(i, j, visited, grid));
                }
            }
        }

        return count;
    }
};