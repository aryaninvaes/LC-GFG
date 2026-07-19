class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> nums;
        for(int i=0; 1LL*i*i<=c; i++ ){
            nums.push_back(i);
        }
        int right=nums.size()-1;
        int left=0;
        while(left<=right){
            long long temp= 1LL*nums[left] * nums[left] + 1LL*nums[right] * nums[right];
            if(temp==c){
                return true;
            }else if(temp < c){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
};