class Solution {
public:
    int n;
    bool isValid(int mid ,vector<int>& nums){
        vector<long long> arr(nums.begin(), nums.end());

        for(int i=0; i<n-1; i++){
            if(arr[i]>mid){
                return false;
            }
            long long buffer = mid- arr[i];
            arr[i+1]= arr[i+1] - buffer;
        }
        return arr[n-1] <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        n=nums.size();
        int maxL= 1;
        int result= 0;
        int maxR= *max_element(nums.begin(), nums.end());

        while(maxL<=maxR){
            int mid= maxL + (maxR-maxL)/2;
            if(isValid(mid, nums)){
                result=mid;
                maxR=mid-1;
            }else{
                maxL=mid+1;
            }
        }
        return result;
    
    }
};