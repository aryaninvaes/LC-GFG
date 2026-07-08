class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> index_freq;
        int n=nums.size();
        if(n==1) return false;

        for(int i=0; i<n ;i++){
            index_freq[nums[i]].push_back(i);
        }

        for(auto &it: index_freq){
            vector<int> &v = it.second;
            for (int i = 1; i < v.size(); i++) {
                if (v[i] - v[i - 1] <= k)
                    return true;
            }
        }
        return false;
    }
};