//BRUTE FORCE
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result= INT_MIN;
        int n= points.size();
        if(n==1){
            return 1;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int count =2;
                int dx= points[i][0]-points[j][0];
                int dy= points[i][1]-points[j][1];
                for(int k=0; k<n; k++){
                    if(points[i]!=points[k] && points[j]!=points[k]){
                        int ndx= points[k][0]-points[i][0];
                        int ndy= points[k][1]-points[i][1];

                            if(dy * ndx == dx * ndy){
                                count++;
                            }
                    }
                }
            result=max(result, count);
            }
        }
        return result;
    }
};