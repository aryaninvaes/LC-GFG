// using dsu to connect the one group of water section together

class DSU{
    vector<int> parent; 
    vector<int> size;

    public:

    DSU(int n){
        parent.resize(n);
        size.resize(n,0);   //intially all sizes are 0;
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]); //path compression
    }

    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        if(x_parent == y_parent){
            return; //both already in same group
        }

        if(size[x_parent] > size[y_parent]){
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }else{
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }
    void setSize(int x, int fishCount){
        size[x] = fishCount;
    }
    int getMaxFishCount(){
        return *max_element(size.begin(), size.end());
    }

};

class Solution {
public:
    vector<vector<int>> directions{{0,1}, {0,-1}, {1,0}, {-1,0}};
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int totalCells = m*n;
        DSU dsu(totalCells);
        //intialise size array with fish count
        for(int i=0; i<m; i++){
            for(int j=0 ;j<n; j++){
                if(grid[i][j]>0){
                    int idx = i*n+j;
                    dsu.setSize(idx, grid[i][j]);
                }
            }
        }


        for(int i=0; i<m; i++){
            for(int j=0 ;j<n; j++){
                if(grid[i][j]>0){
                    int idx = i*n+j;    // 2d array to 1d array; 
                    for(auto &dir: directions){
                        int i_ = i+dir[0];
                        int j_ = j+dir[1];
                        if(i_>=0 && i_<m && j_>=0 && j_<n && grid[i_][j_]>0){
                            int idx_ = i_ * n + j_;//parent index;
                            dsu.Union(idx, idx_);
                        }
                    }
                }
            }
        }
        return dsu.getMaxFishCount();


    }

};


// this is technically bruteforce using bfs traversal for every node;
// we can use dsu to connect 
// class Solution {
// public:
//     int m, n;

//     vector<vector<int>> directions{
//         {0, 1}, {0, -1}, {1, 0}, {-1, 0}
//     };

//     bool isSafe(int x, int y) {
//         return x >= 0 && x < m && y >= 0 && y < n;
//     }

//     int bfs(int i, int j,
//             vector<vector<bool>>& visited,
//             vector<vector<int>>& grid) {

//         visited[i][j] = true;

//         queue<pair<int, int>> q;
//         q.push({i, j});

//         int sum = grid[i][j];

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();  

//             for (auto& dir : directions) {
//                 int x_ = x + dir[0];
//                 int y_ = y + dir[1];

//                 if (isSafe(x_, y_) &&
//                     !visited[x_][y_] &&
//                     grid[x_][y_] > 0) {

//                     visited[x_][y_] = true;
//                     sum += grid[x_][y_];

//                     q.push({x_, y_});
//                 }
//             }
//         }

//         return sum;
//     }

//     int findMaxFish(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();

//         int count = 0;

//         vector<vector<bool>> visited(m, vector<bool>(n, false));

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {

//                 if (grid[i][j] > 0 && !visited[i][j]) {
//                     count = max(count, bfs(i, j, visited, grid));
//                 }
//             }
//         }

//         return count;
//     }
// };