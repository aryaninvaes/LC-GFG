class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int index=INT_MAX;
        int temp=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target){
                if(abs(i - start) < temp){
                    index=i;
                    temp= abs(i-start);
                }
            }
        }
        return temp;
    }
};