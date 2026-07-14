class Solution {
public:
    int MOD=1e9+7;
    int GCD(int a, int b) {
        if (a == 0)
            return b;
        if (b == 0)
            return a;
        if (a == b)
            return a;
        if (a > b)
            return gcd(a - b, b);

        return gcd(a, b - a);
    }
    long long fun(int ind,vector<int>& nums,int sq1,int sq2,vector<vector<vector<long long>>> &dp){
        if(ind==nums.size()){
            if(sq1==sq2 && (sq1!=0))return 1;
            return 0;
        }
        if(dp[ind][sq1][sq2]!=-1)return dp[ind][sq1][sq2];
        int gcds1=GCD(sq1,nums[ind]);
        int gcds2=GCD(sq2,nums[ind]);
        long long takeOne=fun(ind+1,nums,gcds1,sq2,dp);
        long long takeTwo=fun(ind+1,nums,sq1,gcds2,dp);
        long long notTake=fun(ind+1,nums,sq1,sq2,dp);
        return dp[ind][sq1][sq2]=((takeOne+takeTwo)%MOD+notTake)%MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(maxi+1,vector<long long>(maxi+1,-1)));
        return (int)fun(0,nums,0,0,dp)%MOD;
    }
};