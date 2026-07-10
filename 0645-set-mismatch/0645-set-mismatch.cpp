class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> freq;
        int n=nums.size();
        int duplicate=0;
        for(auto it: nums){
            if(freq[it]!=0){
                duplicate=it;

            }
            freq[it]++;
        }
        int swapno=0;
        for(int i=1; i<=n; i++){
            if(freq.find(i)==freq.end()){
                swapno=i;
                break;
            }
        }

        return {duplicate, swapno};
        
    }
};