class Solution {
public:
    bool isPossible(int target, vector<int>& candies, long long k){
        long long piles = 0;
        for(int i=0; i<candies.size(); i++){
            piles += candies[i] / target; 
        }
        return (piles >= k);
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1;
        int right = *max_element(candies.begin(), candies.end());
        int result = 0;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(isPossible(mid, candies, k)){
                result = mid;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return result;
    }
};