class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> arr_min_rows;
        vector<int> arr_max_col;


        for(int i=0; i<m; i++){
            int mini = INT_MAX;
            for(int j=0; j<n; j++){
                mini = min(mini, matrix[i][j]);
            }
            arr_min_rows.push_back(mini);
        }
        for(int i=0; i<n; i++){
            int maxi = INT_MIN;
            for(int j=0; j<m; j++){
                maxi = max(maxi, matrix[j][i]);
            }
            arr_max_col.push_back(maxi);
        }
        vector<int> result;
        for(int x : arr_min_rows) {
            for(int y : arr_max_col) {
                if(x == y) {
                    result.push_back(x);
                }
            }
        }

        return result;
    }
};