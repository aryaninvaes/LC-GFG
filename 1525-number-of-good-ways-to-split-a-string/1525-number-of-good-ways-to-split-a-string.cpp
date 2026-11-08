class Solution {
public:
    int numSplits(string s) {
        unordered_set<char> st1;
        unordered_set<char> st2;
        int n = s.length();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int count = 0;
        for(int i=0; i<n; i++){
            st1.insert(s[i]);
            prefix[i] = st1.size();
        }
        for(int i=n-1; i>=0; i--){
            st2.insert(s[i]);
            suffix[i] = st2.size();
        }
        for(int i=0; i<n-1; i++){
            if(suffix[i+1]==prefix[i]){
                count++;
            }
        }
        return count;
    }
};