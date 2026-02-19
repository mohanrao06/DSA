class Solution {
public:
    int fun(int ind,string s,vector<int> &dp){
        if(s.size()==ind)return 1;
        if(s[ind]=='0')return 0;
        if(dp[ind]!=-1)return dp[ind];
        int one=fun(ind+1,s,dp);
        int two=0;
        if(ind+1<s.size()){
            int sub=stoi(s.substr(ind,2));
            if(sub>=10 && sub<=26){
                two=fun(ind+2,s,dp);
            }

        }
        
        return dp[ind] = one+two;

    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return fun(0,s,dp);
    }
};