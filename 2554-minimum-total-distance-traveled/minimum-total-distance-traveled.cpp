class Solution {
public:
    long long slove(int r,int f,vector<int>& robot,vector<int>& pos,vector<vector<long long>> &dp){
        if(r>=robot.size()){
            return 0;
        }
        if(f>=pos.size()){
            return 1e18;
        }
        if(dp[r][f]!=-1)return dp[r][f];
        long long take=abs(robot[r]-pos[f])+slove(r+1,f+1,robot,pos,dp);
        long long skip=slove(r,f+1,robot,pos,dp);
        return dp[r][f]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int n=robot.size();
        vector<int> pos;
        for(int i=0;i<factory.size();i++){
            int posi=factory[i][0];
            int limit=factory[i][1];
            for(int j=0;j<limit;j++){
                pos.push_back(posi);
            }
        }
        int m=pos.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,-1));
        return slove(0,0,robot,pos,dp);
    }
};