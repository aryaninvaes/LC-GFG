class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int minLen=1e9;

        int sum=0;

        while(j<n){

            sum=sum+nums[j];

            while(sum>=target){
                minLen=min(minLen, j-i+1);
                sum=sum- nums[i];
                i++;
            }
            
        j++;

        }
        if(minLen==1e9){
            return 0;
        }else{
            return minLen;
        }
    
    }
};