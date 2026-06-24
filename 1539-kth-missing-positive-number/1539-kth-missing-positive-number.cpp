class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();

        int start=1;
        int i=0;

        while(i<n){
            if(arr[i]!=start){
                k--;
                if(k==0) return start;
                start++;
            }else{
                i++;
                start++;
            }
        }
        return arr[n-1]+k;

    }
};