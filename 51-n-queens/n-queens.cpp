class Solution {
public:
    void fun(int col,vector<string> &board, vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                fun(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        fun(0,board,ans,n);
        return ans;

    }
    bool isSafe(int r,int c,vector<string> board,int n){
        int drow=r;
        int dcol=c;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q')return false;
            r--;
            c--;
        }
        r=drow;
        c=dcol;
        while(c>=0){
            if(board[r][c]=='Q')return false;
            c--;
        }
        r=drow;
        c=dcol;
        while(r<n && c>=0){
            if(board[r][c]=='Q')return false;
            c--;
            r++;
        }
        return true;

    }
};