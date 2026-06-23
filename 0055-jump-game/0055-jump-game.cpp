class Solution {
private:
    bool function(vector<int>& nums, int currIndex, vector<int>& dp) {
        if (currIndex == nums.size() - 1) {
            return true;
        }
        if (currIndex >= nums.size()) {
            return true;
        }
        if (nums[currIndex] == 0) {
            return false;
        }
        if (dp[currIndex] != -1) {
            return dp[currIndex];
        }

        for (int i = currIndex + 1; i <= currIndex + nums[currIndex]; i++) {
            if (function(nums, i, dp)) {
                return dp[currIndex] = true;
            }
        }
        return dp[currIndex] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return function(nums, 0, dp);
    }
};