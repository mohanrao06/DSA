class Solution {
public:
    void dfs(int r,int c,int drow[],int dcol[],vector<vector<char>>& board,vector<vector<int>> &vis,int n,int m){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nrow=drow[i]+r;
            int ncol=dcol[i]+c;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,drow,dcol,board,vis,n,m);
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<m;i++){
            if(vis[0][i]!=1 && board[0][i]=='O'){
                dfs(0,i,drow,dcol,board,vis,n,m);
            }
            if(vis[n-1][i]!=1 && board[n-1][i]=='O'){
                dfs(n-1,i,drow,dcol,board,vis,n,m);
            }
        }

        for(int j=0;j<n;j++){
            if(vis[j][0]!=1 && board[j][0]=='O'){
                dfs(j,0,drow,dcol,board,vis,n,m);
            }
            if(vis[j][m-1]!=1 && board[j][m-1]=='O'){
                 dfs(j,m-1,drow,dcol,board,vis,n,m);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        

    }
};