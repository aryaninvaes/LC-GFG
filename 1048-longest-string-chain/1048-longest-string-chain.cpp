class Solution {
public:
    static bool comp(string &a, string &b){
        return a.length()<b.length();
    }
    bool isPossible(string &a, string &b){
        if(b.length() - a.length() !=1){
            return false;
        }
        int i=0;
        int j=0;

        while(i < a.length() && j < b.length()){
           if(a[i] == b[j]){
               i++;
               j++;
           }else{
               j++;
           }
        }
        return i==a.length();
    }
    int n;
    int dp[1001][1001];
    int func(vector<string>& words, int prev, int currIndex){
        if(currIndex>=n){
            return 0;
        }
        if(dp[prev+1][currIndex]!=-1){
            return dp[prev+1][currIndex];
        }
        int take=0;
        if(prev==-1 || isPossible(words[prev], words[currIndex])){
            take = 1 + func(words, currIndex, currIndex+1);
        }
        int skip = func(words, prev, currIndex+1);
        return dp[prev+1][currIndex] = max(take, skip);

    }

    int longestStrChain(vector<string>& words) {

        memset(dp, -1, sizeof(dp));
        n=words.size();
        sort(words.begin(), words.end(), comp);
        return func(words, -1, 0);

    }
};