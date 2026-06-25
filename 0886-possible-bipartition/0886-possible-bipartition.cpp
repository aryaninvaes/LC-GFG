class Solution {
public:
    bool bfs(vector<vector<int>>& adjList, int node, vector<int>& visited){
        queue<int> q;
        
        q.push(node);
        visited[node]=1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adjList[node]) {
                if(visited[it]==visited[node]){
                    return false;
                }else if(visited[it]==-1){
                    q.push(it);
                    visited[it]= 1 - visited[node];
                }   
            }
        }
        return true;

    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adjList(n + 1);

        for (auto id : dislikes) {
            adjList[id[0]].push_back(id[1]);
            adjList[id[1]].push_back(id[0]);
        }

        vector<int> visited(n + 1, -1);

        for(int i=1; i<=n; i++){
            if(visited[i]==-1){
                if(bfs(adjList, i, visited)==false){
                    return false;
                }
            }
        }
        return true;

    }
};