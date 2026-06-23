class Solution {
public:
    bool function(string s, string t, int index, int currIndex, vector<vector<int>>& dp){
        if(dp[index][currIndex]!=-1){
            return dp[index][currIndex];
        }

        if(currIndex==s.size()){
            return true;
        }
        if(index==t.size()){
            return false;
        }
        bool take=false; 
        if(s[currIndex]==t[index]){
            take= function(s,t,index+1, currIndex+1,dp);
        }
        bool skip= function(s,t, index+1, currIndex,dp);
        return dp[index][currIndex] = take || skip;
    }
    bool isSubsequence(string s, string t) {
        int n= s.size();
        int m=t.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return function(s,t,0,0,dp);
    }
};