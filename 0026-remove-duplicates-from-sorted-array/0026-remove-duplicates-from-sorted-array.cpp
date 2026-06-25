class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;

        while(j<nums.size()){
            if(nums[i]==nums[j]){
                j++;
            }else{
                i++;
                swap(nums[i], nums[j]);
                j++;
            }
        }

        return i+1;

    }
};

//not the expectied solution this is
//O(n)- space;

// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         map<int, int> mpp;

//         for(int i=0; i<nums.size(); i++){
//             mpp[nums[i]]++;
//         }
//         int i=0;
//         for(auto it: mpp){
//             nums[i]= it.first;
//             i++;
//         }
//         return i;
//     }
// };