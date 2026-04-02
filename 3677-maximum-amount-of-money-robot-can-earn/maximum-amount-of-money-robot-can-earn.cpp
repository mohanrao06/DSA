class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1e9)));

        // base case (last cell)
        for(int k = 0; k < 3; k++){
            int take = coins[n-1][m-1];
            int skip = -1e9;
            if(coins[n-1][m-1] < 0 && k < 2){
                skip = 0;
            }
            dp[n-1][m-1][k] = max(take, skip);
        }

        // fill from bottom-right → top-left
        for(int r = n-1; r >= 0; r--){
            for(int c = m-1; c >= 0; c--){
                for(int k = 0; k < 3; k++){

                    if(r == n-1 && c == m-1) continue;

                    int next = -1e9;

                    if(c+1 < m) next = max(next, dp[r][c+1][k]);
                    if(r+1 < n) next = max(next, dp[r+1][c][k]);

                    int take = coins[r][c] + next;

                    int skip = -1e9;
                    if(coins[r][c] < 0 && k < 2){
                        int next_skip = -1e9;
                        if(c+1 < m) next_skip = max(next_skip, dp[r][c+1][k+1]);
                        if(r+1 < n) next_skip = max(next_skip, dp[r+1][c][k+1]);

                        skip = next_skip;
                    }

                    dp[r][c][k] = max(take, skip);
                }
            }
        }

        return dp[0][0][0];
    }
};