class Solution {
public:
    int n,m,k;
    int dp[51][51][101];
    int MOD = 1e9+7;
    int solve(int index, int cost, int max){
        // base case
        if(index >= n){
            if(cost == k){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[index][cost][max] != -1){
            return dp[index][cost][max];
        }
        int result = 0; 

        for(int i=1;i<=m;i++){
            if(i>max){
                result = (result + solve(index+1,cost+1,i)) % MOD;
            }else{
                result = (result + solve(index+1,cost,max)) % MOD;
            }
        }

        return dp[index][cost][max] = result % MOD; 
    }

    int numOfArrays(int ni, int mi, int ki) { 
        n = ni;
        m = mi; 
        k = ki;

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0); //index, search_cost, max;
    }
};