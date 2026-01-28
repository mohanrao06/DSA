class Solution {
public:
    int maxi(vector<vector<int>>& mat,int col,int n,int m){
        int ind=-1;
        int ele=-1;
        for(int i=0;i<n;i++){
            if(ele<mat[i][col]){
                ind=i;
                ele=mat[i][col];
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
            int mid=(low+high)/2;
            int rowind=maxi(mat,mid,n,m);
            int left=(mid-1>0)?mat[rowind][mid-1]:-1;
            int right=(mid+1<m)?mat[rowind][mid+1]:-1;
            if(mat[rowind][mid]>left && mat[rowind][mid]>right){
                return {rowind,mid};
            }else if(mat[rowind][mid]<left ){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return {-1,-1};

    }
};