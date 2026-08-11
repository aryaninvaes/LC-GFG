class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        // Step 1: Find sum of longest sequential prefix
        int sum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            }
            else {
                break;
            }
        }

        // Step 2: Store all elements
        unordered_set<int> st;

        for(auto x : nums) {
            st.insert(x);
        }

        // Find smallest missing number >= sum
        while(st.count(sum)) {
            sum++;
        }

        return sum;
    }
};