class Solution {
public:
    bool isValid(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){

            if(board[row][i]==c) return false; // row check

            if(board[i][col]==c) return false; // column check

            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false; // box check
        }
        return true;
    }
    bool fun(vector<vector<char>>& board){

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(board,i,j,ch)){
                            board[i][j]=ch;
                            if(fun(board))return true;;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        fun(board);
    }
};