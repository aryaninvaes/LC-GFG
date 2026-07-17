class Solution {
public:
    bool detectCapitalUse(string word) {
        int countsmall=0;
        int countlarge=0;
        for(auto x: word){
            if( x >= 'a' && x <= 'z' ){
                countsmall++;
            }
            if(x>='A' && x<='Z'){
                countlarge++;
            }
        }
        int n=word.length();
        if(countlarge==1 && word[0]>='A' && word[0]<='Z') return true;
        if(countlarge==n || countlarge==0) return true;
        return false;
        
    }
};