class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
    }

};

// class Solution {
// public:
//     vector<int> findOriginalArray(vector<int>& changed) {
//         int size=changed.size();
//         if(size%2!=0){
//             return {};
//         }

//         sort(changed.begin(), changed.end());

//         unordered_map<int, int> mp;
//         for(int &nums : changed){
//             mp[nums]++;

//         }
//         vector<int> result;
//         for(int &num : changed){
//             int twice= 2* num;
//             if(mp[num]==0) continue;

//             if(mp.find(twice)==mp.end() || mp[twice]==0){
//                 return {};
//             }
//             result.push_back(num);
//             mp[num]--;
//             mp[twice]--;
//         }
//         return result;


//     }
// };