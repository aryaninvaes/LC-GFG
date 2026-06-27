class Solution {
public:
    long long modulo_num = 1000000007;

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        long long n = nums.size();

        long long left = 0;
        long long right = n - 1;
        long long ans=0;

        vector<long long>power(n);
        power[0]=1;

        for(int i=1; i<n; i++){
            power[i]= (power[i-1]*2) % modulo_num;
        }

        while (left <= right) {
            if(nums[left]+nums[right] > target){
                right--;
            }
            else{
                
                ans= ( ans + power[right-left] ) % modulo_num;
                left++;
            }
        }
        return ans;
    }
};