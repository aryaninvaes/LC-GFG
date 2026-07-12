class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string temp=to_string(x);
        int left=0;
        int right=temp.length()-1;

        while(left<right){
            if(temp[left]!=temp[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
        
    }
};



// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x<0) return false;

//         int n=x;
//         vector<int> digits;

//         while(n){
//             digits.push_back(n%10);
//             n /= 10;
//         }
//         long long pro=0;
//         for(auto d: digits){
//             pro=pro*10+d;
//         }
//         return pro==x;
        
//     }
// };