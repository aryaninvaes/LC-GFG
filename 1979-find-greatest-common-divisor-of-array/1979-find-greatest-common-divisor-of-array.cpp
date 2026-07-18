class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(auto it: nums){
            maxi= max(maxi, it);
            mini= min(mini, it);
        }
        return gcd(maxi,mini);
    }
};


// TC - 2*O(n)
// class Solution {
// public:
//     int findGCD(vector<int>& nums) {
//         int maxi=*max_element(nums.begin(), nums.end());
//         int mini=*min_element(nums.begin(), nums.end());
//         return gcd(maxi, mini);
//     }
// };