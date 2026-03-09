class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};
    bool dfs(int r,int c,vector<vector<char>>& board, string word,int ind,int n,int m,vector<vector<int>> &vis){
        if(ind == word.size()-1) return true;
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nrow=delrow[i]+r;
            int ncol=delcol[i]+c;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]==word[ind+1]){
                if(dfs(nrow,ncol,board,word,ind+1,n,m,vis))return true;
            }
        }
        
        vis[r][c] = 0; // backtracking
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        int wordsize=word.size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && 
                board[i][j]==word[0]){
                    if(dfs(i,j,board,word,0,n,m,vis))return true;
                }
            }
        }
        return false;
    }
};