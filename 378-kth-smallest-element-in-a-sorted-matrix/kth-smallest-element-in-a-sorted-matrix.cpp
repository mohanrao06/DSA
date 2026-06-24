class Solution {
public:
    int n;
    int m;
    int fun(vector<vector<int>>& matrix, int x){
        int cnt=0;
        int c=m-1;
        for(int r=0;r<n;r++){
            while(c>=0 && matrix[r][c]>x)c--;
            cnt+=(c+1);
            
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n=matrix.size();
        m=matrix[0].size();
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(fun(matrix,mid)>=k){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};