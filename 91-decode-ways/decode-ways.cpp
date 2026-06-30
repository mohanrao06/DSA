class Solution {
public:
    int fun(int ind,string s,vector<int> &dp){
        if(ind==s.size())return 1;
        if(s[ind]=='0')return 0;
        if(dp[ind]!=-1)return dp[ind];
        int oneDigit=fun(ind+1,s,dp);
        int towDigit=0;
        if(ind+1<s.size()){
            int sub=stoi(s.substr(ind,2));
            if(sub>=10 && sub<=26){
                towDigit=fun(ind+2,s,dp);
            }
        }
        return dp[ind]=oneDigit+towDigit;
    }
    int numDecodings(string s) {
        
        int n=s.size();
        if (s[0] == '0')
            return 0;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int oneDigit = 0;
            if (s[i - 1] != '0')
                oneDigit = dp[i - 1];
            int towDigit = 0;
            int sub = stoi(s.substr(i - 2, 2));
            if (sub >= 10 && sub <= 26)
                towDigit = dp[i - 2];

            dp[i] = oneDigit + towDigit;
        }
        return dp[n];
    }
};