class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = count of x
        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[g] = numbers divisible by g
        vector<long long> cnt(mx + 1, 0);
        for (int g = 1; g <= mx; g++) {
            for (int j = g; j <= mx; j += g) {
                cnt[g] += freq[j];
            }
        }

        // exactPairs[g] = pairs having gcd exactly g
        vector<long long> exactPairs(mx + 1, 0);

        for (int g = mx; g >= 1; g--) {
            exactPairs[g] = cnt[g] * (cnt[g] - 1) / 2;
            for (int j = 2 * g; j <= mx; j += g) {
                exactPairs[g] -= exactPairs[j];
            }
        }

        // prefix[i] = number of pairs with gcd <= i
        vector<long long> prefix(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exactPairs[i];
        }

        vector<int> ans;

        for (long long q : queries) {
            // q is 0-indexed
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};
// THIS IS GOOD BUT WILL GIVE TLE
// class Solution {
// public:
//     vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
//         int n=nums.size();
//         vector<long long> result;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 result.push_back(gcd(nums[i], nums[j]));
//             }
//         }
//         sort(result.begin(), result.end());
//         vector<int> ans;
//         for(auto itt: queries){
//             ans.push_back(result[itt]);
//         }
//         return ans;
//     }
// };