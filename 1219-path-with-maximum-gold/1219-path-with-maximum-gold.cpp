class Solution {
public:
    int m;
    int n;

    vector<vector<int>> delInd{{-1,0} , {1,0} , {0,1} , {0,-1}};
    
    int solve(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || row>=m || col<0 || col>=n || grid[row][col]==0){
            return 0;
        }
        int originalGridValue = grid[row][col];
        grid[row][col]=0;

        int maxGold=0;

        for(int i=0; i<4; i++){
            int newx= delInd[i][0] + row;
            int newy= delInd[i][1] + col;
            maxGold = max(maxGold , solve(newx, newy, grid));
        }

        grid[row][col]=originalGridValue;
        return maxGold+originalGridValue;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size();
        n= grid[0].size();

        int maxGold=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){

                if(grid[i][j]!=0){
                    int ans= solve(i, j, grid);
                    maxGold=max(ans, maxGold);
                }
            }
        }
        return maxGold;
    }
};