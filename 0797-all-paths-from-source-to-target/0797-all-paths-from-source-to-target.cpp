class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>>& graph, int node, vector<int>& path){
        if(node==graph.size()-1){
            ans.push_back(path);
            return;
        }

        for(auto next: graph[node]){
            path.push_back(next);
            dfs(graph, next, path);
            path.pop_back();

        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> path= {0};
        dfs(graph, 0, path);
        return ans;
        
    }
};