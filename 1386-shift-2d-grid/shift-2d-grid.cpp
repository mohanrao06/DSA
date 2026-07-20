class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> ans=grid;
        while(k--){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(j==m-1 && i+1<n){
                        ans[i+1][0]=grid[i][j];
                    }else if(i==n-1 && j == m-1){
                        ans[0][0]=grid[i][j];
                    }else{
                        ans[i][j+1]=grid[i][j];
                    }
                    

                }
            }
            grid=ans;
        }
        return ans;
    }
};