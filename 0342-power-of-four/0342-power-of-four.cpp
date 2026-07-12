class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        return ((n&(n-1))==0 && (n-1)%3==0);
    }
};

// class Solution {


// public:
//     bool isPowerOfFour(int n) {
//         if(n<=0){
//             return false;

//         }
//         int x= log(n)/log(4);
//         return (pow(4,x)==n);
//     }
// };

// class Solution {
// public:
//     bool isPowerOfFour(int n) {
//         if(n==0){
//             return false;
//         }
//         while(n%4==0){
//             n=n/4;
//         }
//         return (n==1);
//     }
// };