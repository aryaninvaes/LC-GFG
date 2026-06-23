class Solution {
public:
    int n;

    int solve(vector<int>& nums, int index, int prev,
              vector<vector<int>>& dp) {

        if(index == n)
            return 0;

        if(prev != -1 && dp[index][prev] != -1)
            return dp[index][prev];

        int take = 0;

        if(prev == -1 || nums[index] > nums[prev]) {
            take = 1 + solve(nums, index + 1, index, dp);
        }

        int skip = solve(nums, index + 1, prev, dp);

        int ans = max(take, skip);

        if(prev != -1)
            dp[index][prev] = ans;

        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(nums, 0, -1, dp);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna