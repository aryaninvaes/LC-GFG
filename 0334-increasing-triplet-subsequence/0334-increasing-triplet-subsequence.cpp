class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int num_1 = INT_MAX;
        int num_2 = INT_MAX;

        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= num_1 && arr[i] <= num_2){
                num_1=arr[i];
            }
            else if(arr[i] >= num_1 && arr[i] <= num_2){
                num_2 = arr[i];
            }else{
                return true;
            }
        }
        return false;
    }
};