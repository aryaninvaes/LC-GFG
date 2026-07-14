class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans=0;
        for(auto ch: s){
            ans ^=ch;
        }
        for(auto ch: t){
            ans^= ch;
        }
        return ans;
    }
};

// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         vector<int> freqs(26,0);
//         vector<int> freqt(26,0);
//         for(int i=0; i<s.length()+1; i++){
//             if(i<s.length()){
//                 freqs[s[i]-'a']++;
//             }
//             freqt[t[i]-'a']++;
//         }
//         for(int i=0; i<26; i++){
//             if(freqs[i]!=freqt[i]){
//                 return i+'a';
//             }
//         }        
//         return ' ';
//     }
// };