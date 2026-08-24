class Solution {
public:
    set<int> mp;
    int fun(int currday,vector<int>& days, vector<int>& costs,vector<int> &dp){
        if(currday>days[days.size()-1])return 0;
        if(mp.find(currday)==mp.end()){
            return fun(currday+1,days,costs,dp);
        }
        if(dp[currday]!=-1)return dp[currday];
        int one=costs[0]+fun(currday+1,days,costs,dp);
        int seven=costs[1]+fun(currday+7,days,costs,dp);
        int thirty=costs[2]+fun(currday+30,days,costs,dp);

        return dp[currday]=min(one,min(seven,thirty));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int lastday=days[n-1];
        vector<int> dp(lastday+1,-1);
        for(int i=0;i<n;i++){
            mp.insert(days[i]);
        }

        return fun(1,days,costs,dp);
    }
};