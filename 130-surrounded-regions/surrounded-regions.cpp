class Solution {
public:
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>> &vis){
        vis[r][c]=1;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=drow[i]+r;
            int ncol=dcol[i]+c;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&!vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis);
            }
        }


    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int col=0;col<m;col++){
            if(!vis[0][col] && board[0][col]=='O'){
                dfs(0,col,board,vis);
            }
        }
        for(int col=0;col<m;col++){
            if(!vis[n-1][col]&&board[n-1][col]=='O'){
                dfs(n-1,col,board,vis);
            }
        }
        for(int row=0;row<n;row++){
            if(!vis[row][0] &&board[row][0]=='O'){
                dfs(row,0,board,vis);
            }
        }
        for(int row=0;row<n;row++){
            if(!vis[row][m-1] &&board[row][m-1]=='O'){
                dfs(row,m-1,board,vis);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
        

    }
};