class Solution {
public:
    void slove(int col,vector<vector<string>> &ans,vector<string> &board,vector<int> &left,
        vector<int> &upper,vector<int> &lower,int n){
            if(col==n){
                ans.push_back(board);
                return;
            }
            for(int row=0;row<n;row++){
                if(left[row]==0 && upper[n-1+col-row]==0 && lower[row+col]==0){
                    board[row][col]='Q';
                    left[row]=1;
                    upper[n-1+col-row]=1;
                    lower[row+col]=1;
                    slove(col+1,ans,board,left,upper,lower,n);
                    board[row][col]='.';
                    left[row]=0;
                    upper[n-1+col-row]=0;
                    lower[row+col]=0;


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

        vector<int> left(n,0),upper(2*n-1,0),lower(2*n-1,0);
        slove(0,ans,board,left,upper,lower,n);

        return ans;
    }
};