class Solution {
public:
    int maxi(vector<vector<int>>& mat,int n,int m,int col){
        int maxi=-1;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(maxi<mat[i][col]){
                maxi=mat[i][col];
                ind=i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int row=maxi(mat,n,m,mid);
            int left=mid-1>0?mat[row][mid-1]:-1;
            int right=mid+1<m?mat[row][mid+1]:-1;
            if(mat[row][mid]>left && mat[row][mid]>right){
                return {row,mid};
            }
            else if(mat[row][mid]<left){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};
    }
};