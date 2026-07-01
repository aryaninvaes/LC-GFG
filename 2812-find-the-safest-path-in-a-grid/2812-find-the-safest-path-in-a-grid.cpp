// class Solution {
// public:
//     bool(check)
//     vector<vector<int>> directions={{1,0}, {-1,0}, {0,-1}, {0,1}}; 
//     int maximumSafenessFactor(vector<vector<int>>& grid) {
//         //precalculation of distance from theif for each cell

//         vector<<vector>int> distNearTheif(n, vector<int>(n,-1));
//         queue<pair<int, int>> q;
//         vector<vector<bool>> visited(n, vector<bool>(n, false));

//         //push all cells where theives are present
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j]==1){
//                     visited[i][j]=true;
//                     q.push({i , j});
//                 }
//             }
//         }
//         int level=0;

//         while(!q.empty()){
//             int size= q.size();

//             while(size--){
//                 int curr_i=q.front().first;
//                 int curr_j=q.front().second;
//                 q.pop();
//                 distNearTheif[curr_i][curr_j]=level;
//                 for(vector<int>& dirct: directions){
//                     int new_i = curr_i+dirct[0];
//                     int new_j = curr_j+firect[1];
//                     if(new_i<0 || new_i>=n || new_){
//                         continue;
//                     }
//                     q.push({new_i, new_j})
//                     visited[new_i][new_j]=true;

//                 }



//             }
//             level++;
//         }


//         int l=0;
//         int r=400;
//         int result=0;

//         while(l<=r){
//             int mid_sf= l+(r-l)/2;
//             if(check(distNearTheif, mid_sf)){
//                 result=mid_sfl
//                 l=mid_sf;
//             }else{
//                 r=mid_sf-1;
//             }

//         }
        
//     }
// };


class Solution {
public:
    vector<vector<int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool check(vector<vector<int>>& dist, int sf) {
        int n = dist.size();

        // start or end cannot satisfy safeness factor
        if (dist[0][0] < sf || dist[n-1][n-1] < sf)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n,false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == n-1 && y == n-1)
                return true;

            for(auto &dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if(nx>=0 && nx<n && ny>=0 && ny<n &&
                   !vis[nx][ny] && dist[nx][ny] >= sf) {

                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
        }

        return false;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n,-1));
        vector<vector<bool>> vis(n, vector<bool>(n,false));
        queue<pair<int,int>> q;

        // Multi-source BFS
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    q.push({i,j});
                    vis[i][j]=true;
                }
            }
        }

        int level = 0;

        while(!q.empty()) {
            int sz = q.size();

            while(sz--) {
                auto [x,y] = q.front();
                q.pop();

                dist[x][y] = level;

                for(auto &dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if(nx<0 || nx>=n || ny<0 || ny>=n)
                        continue;

                    if(vis[nx][ny])
                        continue;

                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
            level++;
        }

        int low = 0;
        int high = 2 * n;   // maximum possible distance is <= 2*(n-1)
        int ans = 0;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(check(dist, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};