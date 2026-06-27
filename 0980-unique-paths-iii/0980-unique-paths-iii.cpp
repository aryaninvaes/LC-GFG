class Solution {
private:
    void function(vector<vector<int>>& grid, int x, int y, int &ways, int& count){
        int m=grid.size();
        int n=grid[0].size();

        if(grid[x][y]==2){
            if(count==0){
            ways=ways+1;
            }
            return;
        }
        int temp=grid[x][y];
        grid[x][y]=3;
        count--;
    
            int delx[]={-1,0,1,0};
            int dely[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int newx=x+delx[i];
                int newy=y+dely[i];
                if(newx>=0 && newx<m && newy>=0 && newy<n){
                    if(grid[newx][newy]!=3 && grid[newx][newy]!=-1){
                        function(grid, newx, newy, ways, count);   
                    }
                }
            }

        count++;
        grid[x][y]=temp;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int countObstacle=0;
        int start_x=0;
        int start_y=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0 || grid[i][j]==1){
                    if(grid[i][j]==1){
                        start_x=i;
                        start_y=j;
                    }
                    countObstacle++;
                }
            }
        }

        int ways=0;
        function(grid,start_x, start_y, ways, countObstacle);
        return ways;
    }
};