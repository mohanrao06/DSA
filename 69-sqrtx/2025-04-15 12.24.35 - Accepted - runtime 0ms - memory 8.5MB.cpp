class Solution {
public:
    int mySqrt(int n) {
        long long ans=0;
        int low=1;
        int high=n;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid==n)return mid;
            else if(mid*mid<n){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};