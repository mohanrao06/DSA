class Solution {
public:
    int fun(int ind,vector<int>& nums,vector<int> &dp){
        if(ind==nums.size()-1)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int cnt=1e9;
        for(int i=1;i<=nums[ind];i++){
            if(ind+i<nums.size()){
                cnt=min(cnt,1+fun(ind+i,nums,dp));
            }
        }
        return dp[ind]=cnt;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);


        return fun(0,nums,dp);

    }
};