class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int left=0; 
        int n= nums.size();
        int right= n-1;

        sort(nums.begin(), nums.end());
        int maxi= INT_MIN;
        while(left<right){
            int sum= nums[left]+nums[right];
            maxi= max(maxi, sum);
            left++;
            right--;
        }
        return maxi;
    }
};