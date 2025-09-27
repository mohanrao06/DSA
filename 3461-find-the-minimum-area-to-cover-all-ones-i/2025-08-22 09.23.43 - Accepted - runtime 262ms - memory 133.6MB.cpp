class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxcol=-1;
        int mincol=m;
        int maxrow=-1;
        int minrow=n;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxcol=max(maxcol,j);
                    mincol=min(mincol,j);

                    maxrow=max(maxrow,i);
                    minrow=min(minrow,i);

                }
            }
        }
        int length=(maxrow-minrow+1)*(maxcol-mincol+1);
        return length;

    }
};