class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> col_arr(m,0);
        vector<int> row_arr(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    col_arr[j]=1;
                    row_arr[i]=1;
                    
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(row_arr[i]==1 || col_arr[j]==1){
                    matrix[i][j]=0;
                }
            }
        }

        
    }
};