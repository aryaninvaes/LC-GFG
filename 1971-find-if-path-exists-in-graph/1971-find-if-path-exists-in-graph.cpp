class Solution {
public:
    bool function(vector<vector<int>>& adjList, int source, int destination, vector<int>& visited){
        queue<int> q;
        q.push(source);
        visited[source]=1;

        while(!q.empty()){
            int node= q.front();
            q.pop();

            if(node==destination) return true;

            for(auto members: adjList[node]){
                if(!visited[members]){
                    if(members==destination){
                        return true;
                    }
                    q.push(members);
                    visited[members]=1;
                }
            }   
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         vector<vector<int>> adjList(n);
         vector<int> visited(n,0);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        return function(adjList, source, destination, visited);
    }
};