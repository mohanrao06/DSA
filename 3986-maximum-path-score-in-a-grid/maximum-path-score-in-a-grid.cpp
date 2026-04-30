class Solution {
public:
    int k;
    int fun(int i,int j,int cost,vector<vector<int>> &arr,vector<vector<vector<int>>>&dp){
        if(i<0 || j<0)return -1e9;
        if(cost>k)return -1e9;
        int addcost=(arr[i][j]==0?0:1);
        int addscore = (arr[i][j] == 2 ? 2 : arr[i][j]);
        if(i==0 && j==0){
            if(cost+addcost<=k){
                return addscore;
            }else{
                return -1e9;
            }
        }
        if(dp[i][j][cost]!=-1)return dp[i][j][cost];
        
        int up=addscore+fun(i-1,j,cost+addcost,arr,dp);
        int down=addscore+fun(i,j-1,cost+addcost,arr,dp);
        return dp[i][j][cost]= max(up,down);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        this->k=k;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
       int ans= fun(n-1,m-1,0,grid,dp);
        if(ans<0)return -1;
        return ans;
    }
};