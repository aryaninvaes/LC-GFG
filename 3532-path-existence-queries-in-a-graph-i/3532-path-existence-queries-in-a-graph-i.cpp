class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n, -1);
        int compID=0;
        component[0]= compID;

        for(int i=1; i<n; i++){
            if((nums[i] - nums[i-1]) <= maxDiff){
                component[i]=component[i-1];
            }else{
                compID++;
                component[i] = compID; 
            }
        }
        vector<bool> ans;
        for(auto &x: queries){
            int source=x[0];
            int desti=x[1];
            if(component[source]== component[desti]){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};