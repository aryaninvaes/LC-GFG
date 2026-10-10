class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp;
        for(char &c: magazine){
            mpp[c]++;
        }
        for(auto &ch: ransomNote){
            if(mpp.find(ch)!=mpp.end()){
                mpp[ch]--;
                if(mpp[ch]==0) mpp.erase(ch);
            }else{
                return false;
            }
        }
        return true;
    }
};