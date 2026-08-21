class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<routes.size(); i++){
            for(auto &stops: routes[i]){
                adj[stops].push_back(i);
            }
        }
        queue<int> q;
        vector<bool > visited(501, false);
        for(auto &route:adj[source]){
            q.push(route);
            visited[route] = true;

        }
        int bus = 1;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                int route_idx = q.front();
                q.pop();

                for(auto &stop: routes[route_idx]){
                    if(stop==target){
                        return bus;
                    }
                    for(auto &next_route: adj[stop]){
                        if(!visited[next_route]){
                            visited[next_route]=true;
                            q.push(next_route);
                        }
                    }
                }
            }
            bus++;
        }
        return -1;
    }
};