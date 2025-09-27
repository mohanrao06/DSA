class Solution {
public:
    void fun(int row,int col,vector<vector<int>>& grid,bool asc,int n){
        int i=row;
        int j=col;
        vector<int> temp;
        while(i<n&& j<n){
            temp.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(asc){
            sort(temp.begin(),temp.end());
        }else{
            sort(rbegin(temp),rend(temp));
        }
        i=row;
        j=col;
        for(int it:temp){
            grid[i][j]=it;
            i++;
            j++;
        }

    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        
        for(int row=0;row<n;row++){
            fun(row,0,grid,0,n);
        }
        for(int col=1;col<n;col++){
            fun(0,col,grid,true,n);
        }
        return grid;
    }
};