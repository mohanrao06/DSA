class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    bool dfs(int r,int c,vector<vector<char>>& grid,vector<vector<int>> &vis,int pr,int pc){
        int n=grid.size();
        int m=grid[0].size();
        vis[r][c]=1;
        char ch=grid[r][c];
        for(int i=0;i<4;i++){
            int nr=r+delrow[i];
            int nc=c+delcol[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && ch==grid[nr][nc]){
                if(!vis[nr][nc]){
                    if(dfs(nr,nc,grid,vis,r,c))return true;
                }else if(nr != pr || nc != pc){
                    return true;
                }
            }

        }
        return false;

    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    if(dfs(i,j,grid,vis,-1,-1))return true;
                }
            }
        }
        return false;
    }
};