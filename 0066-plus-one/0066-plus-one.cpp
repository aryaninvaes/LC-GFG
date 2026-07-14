class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int> result;

        int carry=0;
        for(int i=n-1; i>=0; i--){
            int new_sum = digits[i]+carry;
            if(i==n-1){
                new_sum += 1;
            }
            result.push_back(new_sum%10);
            carry = new_sum/10;
        }
        if(carry){
            result.push_back(1);
        }
        reverse(result.begin(), result.end());
        return result;
        
        
    }
};


//BRUTE FORCE
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         long long pro=0;
//         for(auto it: digits){
//             pro=pro*10 + it;
//         }
//         pro++;
//         vector<int> result;
//         while(pro){
//             result.push_back(pro%10);
//             pro /=10;
//         }
//         reverse(result.begin(), result.end());
//         return result;
    
//     }
// };