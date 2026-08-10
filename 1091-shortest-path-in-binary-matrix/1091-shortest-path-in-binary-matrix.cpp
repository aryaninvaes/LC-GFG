// 2 APPROACH - DIJKSTARS AND BFS

//1) USING DIJKSTARS APPROACH

class Solution {
public:
    vector<vector<int>> direction{{1,1}, {0,1}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,0}, {1,-1}};
    int N;

    bool isSafe(int x, int y){
        if(x>=0 && x<N && y>=0 && y<N){
            return true;
        }
        return false;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> result(n, vector<int>(n, INT_MAX));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        if(grid[0][0]==1){
            return -1;
        }

        N = grid.size();

        result[0][0]=0;
        pq.push({0, {0,0}});
        grid[0][0] = 1;

        while(!pq.empty()){
            auto it = pq.top();
            int d = it.first;
            int curr_x = it.second.first;
            int curr_y = it.second.second;
            pq.pop();

            for(int i=0; i<8; i++){
                int new_x = curr_x + direction[i][0];
                int new_y = curr_y + direction[i][1];
                int distance = 1;

                if(isSafe(new_x, new_y) && d + distance < result[new_x][new_y]){
                    if(grid[new_x][new_y]==0){
                        result[new_x][new_y] = d+distance ;
                        grid[new_x][new_y] = 1;
                        pq.push({d+distance, {new_x, new_y}});
                    }
                }
            }
        }
        if(result[n-1][n-1]==INT_MAX){
            return -1;
        }
        return result[n-1][n-1] + 1;
    }
};




// USING BFS APPROACH

// class Solution {
// public:
// int N;
//     vector<vector<int>> direction{{1,1}, {0,1}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,0}, {1,-1}};
//     bool isSafe(int x, int y){
//         if(x>=0 && x<N && y>=0 && y<N){
//             return true;
//         }
//         return false;
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         N = grid.size();
        
//         if(grid[0][0] != 0){
//             return -1;
//         }

//         queue<pair<int, int>> q;
//         q.push({0,0});
//         grid[0][0]=1;

//         int level = 0;

//         while(!q.empty()){
//             int n = q.size();
//             while(n--){
//                 auto curr = q.front();
//                 q.pop();

//                 int curr_x = curr.first;
//                 int curr_y = curr.second;
//                 if(curr_x == N-1 && curr_y == N-1){
//                     return level+1;
//                 }

//                 for(auto dir: direction){
//                     int x = curr_x + dir[0];
//                     int y = curr_y + dir[1];

//                     if(isSafe(x,y) && grid[x][y]!=1){
//                         q.push({x,y});
//                         grid[x][y] = 1;

//                     }
//                 }
//             }
//             level++;
//         }
//         return -1;
//     }
// };