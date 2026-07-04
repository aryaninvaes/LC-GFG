class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto x: nums){
            sum=sum+x;
        }
        int n=nums.size();

        for(int i=0; i<n; i++){
            int leftSum=0;
            for(int j=0; j<i; j++){
                leftSum=leftSum+nums[j];
            }
            if(leftSum == sum - leftSum - nums[i]){
                return i;
            }
        }
        return -1;



    }
};