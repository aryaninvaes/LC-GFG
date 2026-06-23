class Solution {
public:
    void function(vector<vector<int>>& rooms, vector<int>& visited){
        queue<int> q;
        q.push(0);
        visited[0]=1;

        while(!q.empty()){
            int node= q.front();
            q.pop();

            for(auto it: rooms[node]){
                if(!visited[it]){
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);

        function(rooms, visited);

        for(int i=0; i<rooms.size(); i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
};