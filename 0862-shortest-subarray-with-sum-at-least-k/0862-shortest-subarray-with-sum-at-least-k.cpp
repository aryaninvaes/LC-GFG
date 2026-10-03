class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k){
        int n = nums.size();
        deque<int> deq;
        vector<long long> cummSum(n, 0);
        int result = INT_MAX;
        int j = 0;

        while(j<n){
            if(j==0){
                cummSum[0] = nums[0];
            }else{
                cummSum[j] = cummSum[j-1]+nums[j]; 
            }

            if(cummSum[j] >= k ){
                result = min(result, j+1);
            }

            while(!deq.empty() && cummSum[j] - cummSum[deq.front()] >= k){
                result = min(result, j-deq.front());
                deq.pop_front();
            }
            while(!deq.empty() && cummSum[j] <= cummSum[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(j);
            j++;
        }
    return result==INT_MAX? -1 : result;
    }
};