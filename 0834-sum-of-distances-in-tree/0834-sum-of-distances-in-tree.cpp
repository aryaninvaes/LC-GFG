class Solution {
public:
    int N;
    int root_result = 0;
    vector<int> count;
    int dfsBase(unordered_map<int, vector<int>>& adj, int curr_node, int prev_node, int depth){
        int count_node=1;
        for(auto &child: adj[curr_node]){
            if(child == prev_node) continue;
            count_node += dfsBase(adj, child, curr_node, depth+1);
        }
            root_result += depth;
        count[curr_node] = count_node;
        return count_node;
        
    }
    void DFS(unordered_map<int, vector<int>> &adj, int curr, int prev, vector<int>& result){
        for(auto &child: adj[curr]){
            if(child == prev)continue;
            result[child] = result[curr] + N -2*count[child];
        DFS(adj, child, curr, result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.resize(n, 0);
        unordered_map<int, vector<int>> adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfsBase(adj, 0, -1, 0);
        vector<int> result(n,0);
        result[0] = root_result;
        DFS(adj, 0, -1, result);
        return result;
    }
};