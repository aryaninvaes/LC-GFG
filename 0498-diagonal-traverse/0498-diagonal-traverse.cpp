class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        vector<int> result;
        map<int, vector<int>> func;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                func[i + j].push_back(mat[i][j]);
            }
        }
        for (auto it : func) {
            int tempSize = it.second.size();
            if (it.first % 2 != 0) {
                // sort(it.second.begin(), it.second.end());
                reverse(it.second.begin(), it.second.end());
            }
            while (!it.second.empty()) {
                result.push_back(it.second.back());
                it.second.pop_back();

            }
        }
        return result;
        
    }
};