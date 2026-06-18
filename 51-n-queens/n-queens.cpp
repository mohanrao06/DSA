class Solution {
public:
    void fun(int row,vector<string> &board,vector<vector<string>> &ans,int n){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int c=0;c<n;c++){
            if(isVaild(row,c,board,n)){
                board[row][c]='Q';
                fun(row+1,board,ans,n);
                board[row][c]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> board(n);
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        fun(0,board,ans,n);
        return ans;
    }
    bool isVaild(int r,int c,vector<string> &board,int n){
        int row=r;
        int col=c;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--;
            col--;
        }
        row = r;
        col = c;

        while(row >= 0 && col < board.size()) {
            if(board[row][col] == 'Q') return false;
            row--;
            col++;
        }
        row=r;
        col=c;
         while(row>=0){
            if(board[row][col]=='Q')return false;
            row--;
        }
        return true;

    }
};