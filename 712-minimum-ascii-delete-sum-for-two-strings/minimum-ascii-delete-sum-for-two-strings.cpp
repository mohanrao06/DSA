class Solution {
public:
    int fun(int i,int j,string &s1, string &s2,vector<vector<int>> &dp,int n,int m){
        if(i>=n && j>=m)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>=n){
            return dp[i][j]=s2[j]+fun(i,j+1,s1,s2,dp,n,m);
        }else if(j>=m){
            return dp[i][j]=s1[i]+fun(i+1,j,s1,s2,dp,n,m);
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=fun(i+1,j+1,s1,s2,dp,n,m);
        }

        
        int del_i=s1[i]+fun(i+1,j,s1,s2,dp,n,m);
        int del_j=s2[j]+fun(i,j+1,s1,s2,dp,n,m);

        return dp[i][j]=min(del_i,del_j);

    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(0,0,s1,s2,dp,n,m);
    }
};