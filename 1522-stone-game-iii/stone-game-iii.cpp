class Solution {
public:
    int fun(int i,vector<int>& s,int n,vector<int> &dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int currVal=s[i]-fun(i+1,s,n,dp);
        if(i+1<n){
            currVal=max(currVal,s[i]+s[i+1]-fun(i+2,s,n,dp));
        }
        if(i+2<n){
            currVal=max(currVal,s[i]+s[i+1]+s[i+2]-fun(i+3,s,n,dp));
        }
        return dp[i]=currVal;
        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,-1);
        int score=fun(0,stoneValue,n,dp);
        if(score>0)return "Alice";
        else if(score<0)return "Bob";
        return "Tie";
    }
};