class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=1;i<m;i+=1){
            for(int j=1;j<n;j+=1){
                if(matrix[i][j]!=matrix[i-1][j-1]){
                    return false;
                }
            }
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m= matrix.size();
//         int n= matrix[0].size();
//         map<int, set<int>> func;

//         for(int i=0; i<m;i++){
//             for(int j=0; j<n; j++){
//                 func[(j-i)].insert(matrix[i][j]);
//                 if(func[(j-i)].size()>1){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }
// };