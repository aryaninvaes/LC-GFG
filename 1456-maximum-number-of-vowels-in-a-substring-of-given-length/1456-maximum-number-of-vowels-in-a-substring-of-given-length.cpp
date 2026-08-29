class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        int left = 0;
        int countVowel = 0;
        int ans = 0;
        for(int right = 0; right<s.length(); right++){
            if(isVowel(s[right])){
                countVowel++;
            }
            if(right-left+1 == k){
                ans = max(ans, countVowel);
                if(isVowel(s[left])){
                    countVowel--;
                }
                left++;
            }
        }
        return ans;
    }
};