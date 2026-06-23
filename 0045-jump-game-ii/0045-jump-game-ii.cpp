class Solution {
private:
    int function(vector<int>& nums, int currIndex, vector<int>& dp) {
        int n=nums.size();
        if (currIndex >= n-1) {
            return 0;
        }
        if (dp[currIndex] != -1) {
            return dp[currIndex];
        }
        int ans=1e9;

        for (int i = currIndex + 1; i <= min(n-1,currIndex + nums[currIndex]); i++) {
            int mini= 1 + function(nums, i, dp);
            ans=min(ans, mini);
        }
        return dp[currIndex] = ans;
    }
public:

    int jump(vector<int >& nums) {
        
        int n= nums.size();
        vector<int> dp(n+1, -1);

        return function(nums, 0, dp);
         
    }
};