class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n= points.size();
        if(n==1) return 1;

        int result=0;

        for(int i=0; i<n; i++){
            unordered_map<string, int> mpp;
            for(int j=0; j<n; j++){
                if(j==i){
                    continue;
                }
                auto dy = points[j][1] - points[i][1];// y2-y2
                auto dx = points[j][0] - points[i][0]; // x2-x1;

                auto gcd = __gcd(dx, dy);
                string key_theta= to_string(dy/gcd)+"_"+to_string(dx/gcd);

                mpp[key_theta]++;
            }
            for(auto &it : mpp){
                result= max(result, it.second + 1);
            }
        }
        return result;
    }
};

// USING THE C++ atan2(dy,dx)  function
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int n= points.size();
//         if(n==1) return 1;

//         int result=0;

//         for(int i=0; i<n; i++){
//             unordered_map<double, int> mpp;
//             for(int j=0; j<n; j++){
//                 if(j==i){
//                     continue;
//                 }
//                 auto dy = points[j][1] - points[i][1];// y2-y2
//                 auto dx = points[j][0] - points[i][0]; // x2-x1;
//                 auto theta= atan2(dy, dx);
//                 mpp[theta]++;
//             }
//             for(auto &it : mpp){
//                 result= max(result, it.second + 1);
//             }
//         }
//         return result;
//     }
// };


//BRUTE FORCE
// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         int result= INT_MIN;
//         int n= points.size();
//         if(n==1){
//             return 1;
//         }
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int count =2;
//                 int dx= points[i][0]-points[j][0];
//                 int dy= points[i][1]-points[j][1];
//                 for(int k=0; k<n; k++){
//                     if(points[i]!=points[k] && points[j]!=points[k]){
//                         int ndx= points[k][0]-points[i][0];
//                         int ndy= points[k][1]-points[i][1];

//                             if(dy * ndx == dx * ndy){
//                                 count++;
//                             }
//                     }
//                 }
//             result=max(result, count);
//             }
//         }
//         return result;
//     }
// };