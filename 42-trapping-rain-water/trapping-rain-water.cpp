class Solution {
public:
    int trap(vector<int>& arr) {

        int n=arr.size();
        int ans=0;
        int l=0;
        int r=n-1;
        int lmax=0;
        int rmax=0;
        while(l<r){
            if(arr[l]<arr[r]){
                if(lmax>arr[l]){
                    ans+=lmax-arr[l];
                }else{
                    lmax=arr[l];
                }
                l++;
            }else{
                if(rmax>arr[r]){
                    ans+=rmax-arr[r];
                }else{
                    rmax=arr[r];
                }
                r--;
            }
        }
        return ans;
    }
};