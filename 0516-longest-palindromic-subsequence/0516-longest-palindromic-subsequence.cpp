class Solution {
public:
    int dp[1001][1001];
    int solve(string &s, int start, int end){
        if(start == end){
            return 1;
        }
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        if(s[start] == s[end]){
            return dp[start][end] = 2 + solve(s, start+1, end-1);
        }else{
            return dp[start][end] = max(solve(s, start+1, end), solve(s, start, end-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        return solve(s, 0, n-1);
    }
};



// MEMORY LIMIT EXCEED

// class Solution {
// public:
//     int dp[1001][1001];
//     int solve(string s1, string s2, int i, int j){
//         if(i>=s1.length() || j>=s2.length()){
//             return 0;
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int ans = 0;
//         if(s1[i] == s2[j]){
//             return dp[i][j] = 1+ solve(s1,s2,i+1,j+1);
//         }else{
//             return dp[i][j] = max(solve(s1, s2, i+1,j), solve(s1,s2,i,j+1));
//         }
//     }

//     int longestPalindromeSubseq(string s) {
//         memset(dp, -1, sizeof(dp));
//         string new_s = s;
//         reverse(new_s.begin(), new_s.end());
//         return solve(s, new_s, 0, 0);
//     }
// };