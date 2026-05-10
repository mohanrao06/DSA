class Solution {
public:
    int fun(int ind,vector<int>& nums, int target,int steps,vector<int> &dp){
        if(ind==0){
            return 0;
        }
        if(dp[ind]!=-2)return dp[ind];
        int ans=-1;
        for(int i=ind-1;i>=0;i--){
            long long diff=nums[ind]-nums[i];
            if(diff>= -target && diff<= target){
                int prev = fun(i,nums,target,steps+1,dp);
                if(prev!=-1){
                    ans=max(ans,prev+1);
                }
            }
        }
        return dp[ind] =ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> dp(n,-2);
        return fun(n-1,nums,target,0,dp);
    }   
};