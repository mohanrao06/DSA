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
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return fun(n-1,m-1,obstacleGrid,dp);
    }
};