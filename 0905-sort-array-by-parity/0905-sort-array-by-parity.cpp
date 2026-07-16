class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int move=0;
        int right=n-1;
        while(move<right){
            if(nums[move]%2==0){
                swap(nums[move], nums[left]);
                left++;
                move++;
            }else{
                swap(nums[move], nums[right]);
                right--;
            }
        }
        return nums;
        
    }
};