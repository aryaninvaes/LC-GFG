class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> result;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            if(i%2==0){
                for(int j=0; j<n; j++){
                    result.push_back(grid[i][j]);
                }
            }else if(i%2!=0){
                for(int j=n-1; j>=0; j--){
                    result.push_back(grid[i][j]);
                }
            }
        }
        vector<int> ans;
        for(int i=0; i<result.size(); i+=2){
            ans.push_back(result[i]);
        }
        return ans;
    }
};