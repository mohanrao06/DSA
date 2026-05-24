class Solution {
public:
    int slove(int i,vector<int>& arr,int d,vector<int> &dp,int n){
        if(dp[i]!=-1)return dp[i];
        int res=1;
        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[j]>=arr[i])break;
            res=max(res,1+slove(j,arr,d,dp,n));
        }
        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[j]>=arr[i])break;
            res=max(res,1+slove(j,arr,d,dp,n));
        }
        return dp[i]=res;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> dp(n+1,-1);
        int res=0;
        for(int i=0;i<n;i++){
            res=max(res,slove(i,arr,d,dp,n));
        }
        return res;
    }
};