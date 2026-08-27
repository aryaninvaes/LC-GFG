class Solution {
public:
    bool isPerfectSquare(long long num) {
        long long left = 1;
        long long right = num;
        while(left<=right){
            long long mid = left + (right-left)/2;
            if(mid*mid == num){
                return true;
            }else if(mid*mid<num){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
};


//BRUTE FORCE
// class Solution {
// public:
//     bool isPerfectSquare(long long num) {
//         for(long long i=1; i*i<=num; i++){
//             if(i*i == num){
//                 return true;
//             }
//         }
//         return false;
//     }
// };