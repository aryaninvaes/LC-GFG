class Solution {
public:
    const int MOD = 1e9 + 7;
    int MIN_PROFIT;
    int dp[101][101][101];
    int solve(int index, int n, int curr_profit, vector<int>& group, vector<int>& profit){
        if(index>=profit.size()){
            if(curr_profit >= MIN_PROFIT){
                return 1;
            }else{
                return 0;
            }
        }
        if(dp[index][n][curr_profit]!=-1){
            return dp[index][n][curr_profit];
        }

        int not_take = solve(index+1, n, curr_profit, group, profit);

        int take = 0;
        if(n>=group[index]){
            int new_profit = min(MIN_PROFIT,
                                 curr_profit + profit[index]);
            take = solve(index+1, n - group[index], new_profit , group, profit);
        } 
        return dp[index][n][curr_profit] = (take + not_take)%MOD;


    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        MIN_PROFIT = minProfit;
        memset(dp, -1, sizeof(dp));
        return solve(0, n, 0, group, profit);
    }
};