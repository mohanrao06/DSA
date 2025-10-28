class Solution {
public:
    int fun(int r,int c,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(r<0 || c<0)return 0;
        if(obstacleGrid[r][c]==1)return 0;
        if(r==0 && c==0)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int up=fun(r-1,c,obstacleGrid,dp);
        int left=fun(r,c-1,obstacleGrid,dp);
        return dp[r][c]= up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1)dp[i][j]=0;
                else if(i==0 && j==0)dp[i][j]=1;
                else{
                    int up=0;
                    int left=0;
                    if(i>0)up=dp[i-1][j];
                    if(j>0)left=dp[i][j-1];
                    dp[i][j]=up+left;
                }

            }
        }
        return dp[n-1][m-1];
    }
};