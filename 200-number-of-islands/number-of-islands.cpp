class Solution {
public:
    void DFS(vector<vector<char>>& grid,vector<vector<int>> &vis,int delrow[],int delcol[],int r,int c){
        vis[r][c]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n &&ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                DFS(grid,vis,delrow,delcol,nrow,ncol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    DFS(grid,vis,delrow,delcol,i,j);
                    cnt++;
                }
            }
        }
        return cnt;

        
    }
};