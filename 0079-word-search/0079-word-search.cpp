class Solution {
public:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool dfs(vector<vector<char>>& board, int i, int j,
             string& word, int index) {

        int m = board.size();
        int n = board[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] == '$' ||
            board[i][j] != word[index]) {
            return false;
        }

        if (index == word.length() - 1) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (dfs(board, new_i, new_j, word, index + 1)) {
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};