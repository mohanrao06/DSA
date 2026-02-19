class Solution {
public:
    
    int dfs(vector<int>& nums,int ind,vector<int> &dp){
        if(ind==nums.size()-1)return 0;
        if(ind>=nums.size())return INT_MAX;
        if(dp[ind]!=-1)return dp[ind];
        int mini=INT_MAX;
        for(int i=1;i<=nums[ind];i++){
            int ans=dfs(nums,ind+i,dp);
            if(ans!=INT_MAX)
            mini=min(mini,ans+1);
        }
        return dp[ind]=mini;

    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n <= 1) return 0;
        vector<int> dp(n,INT_MAX);
        
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int mini=INT_MAX;
            for(int j=1;j<=nums[i] && i+j<n;j++){
                if(dp[i+j]!=INT_MAX){
                    mini=min(dp[i+j]+1,mini);
                }
            }
            dp[i]=mini;
        }
        return dp[0];
    }
};