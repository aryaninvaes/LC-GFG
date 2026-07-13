class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";

        for (char ch : s) {
            if ((ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') ||
                (ch >= '0' && ch <= '9')) {

                if (ch >= 'A' && ch <= 'Z')
                    ch = ch - 'A' + 'a';

                temp += ch;
            }
        }

        int left = 0;
        int right = temp.size() - 1;

        while (left < right) {
            if (temp[left] != temp[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string s) {
//         string temp="";
//         for(char str: s){
//             if(isalnum(str)){
//                 temp += tolower(str);
//             }
//         }
//         int left=0; 
//         int right=temp.length()-1;
//         while(left<right){
//             if(temp[left]!=temp[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//     }
// };