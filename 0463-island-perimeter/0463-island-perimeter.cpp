class Solution {
public:
    int m;
    int n;
    void func(int row, int col, int & perimeter, vector<vector<int>>& grid){
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0; i<4; i++){
            int newrow = row+delrow[i];
            int newcol = col+delcol[i];
            if(newrow < 0 || newrow >= m || newcol < 0 || newcol >= n){
                perimeter++;
                continue;
            }
            if(grid[newrow][newcol]==0){
                perimeter++;
            }   
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter=0;
        m=grid.size();
        n=grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n;j++){
                if(grid[i][j]==1){
                    func(i,j,perimeter, grid);
                }

            }
        }
        return perimeter;
        
    }
};