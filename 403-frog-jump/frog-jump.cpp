class Solution {
public:
    bool fun(int ind,int k,vector<int>& stones,unordered_map<int,int> &mp, vector<vector<int>> &dp){
        if(ind==stones.size()-1)return true;
        // if(ind>=stones.size())return false;
        if(dp[ind][k]!=-1)return dp[ind][k];
        for(int i=k-1;i<=k+1;i++){
            if(i<=0){
                continue;
            }
            int target=stones[ind]+i;
            if(mp.find(target)!=mp.end()){
                if(fun(mp[target],i,stones,mp,dp))return dp[ind][k]=1;
            }
        }
        return dp[ind][k]=0;   
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,int> mp;
       vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        if (stones[1] != 1)
            return false;
        return fun(1,1,stones,mp,dp);
    }
};