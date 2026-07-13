class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(char str: s){
            if(isalnum(str)){
                temp += tolower(str);
            }
        }
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