class Solution {
public:
    bool fun(int ind,vector<int>& nums){
        if(ind==nums.size()-1)return true;
        if(nums[ind]==0)return false;

        for(int i=1;i<=nums[ind];i++){
            if(ind+i<nums.size()){
                if(fun(ind+i,nums))return true;;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            for(int steps=1;steps<=nums[i];steps++){
                if(i+steps<n){
                    if(dp[i+steps]){
                        dp[i]=1;
                        break;
                    }
                        
                }
            }
        }
        return dp[0];
    }
};