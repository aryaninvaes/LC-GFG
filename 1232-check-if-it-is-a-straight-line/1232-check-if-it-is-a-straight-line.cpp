class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        

        for(int i=1; i<coordinates.size()-1; i++){
            
            int dx1 = coordinates[0][0] - coordinates[i][0];
            int dy1 = coordinates[0][1] - coordinates[i][1];

            int dx2 = coordinates[0][0] - coordinates[i+1][0];
            int dy2 = coordinates[0][1] - coordinates[i+1][1];
            if(dx1 * dy2 != dx2 * dy1){
                return false;
            }
        }

        return true;

    }
};