class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,i,j,0,word))return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,int r,int c,int ind, string word){
        if(ind==word.size()){
            return true;
        }
        int row=board.size();
        int col=board[0].size();
        if(r<0 || r>=row || c<0 || c>=col){
            return false;

        }
        if(board[r][c]==' ' || board[r][c]!=word[ind])return false;
        char ch=board[r][c];
        board[r][c]=' ';
        if(dfs(board,r-1,c,ind+1,word) || dfs(board,r+1,c,ind+1,word)||
        dfs(board,r,c+1,ind+1,word) || dfs(board,r,c-1,ind+1,word)){
            return true;
        }
         board[r][c]=ch;
         return false;
    }
};