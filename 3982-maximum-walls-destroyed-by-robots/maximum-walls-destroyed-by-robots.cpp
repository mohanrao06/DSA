class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> dp;
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<P> robodist(n);
        for(int i=0;i<n;i++){
            robodist[i]={robots[i],distance[i]};
        }
        sort(robodist.begin(),robodist.end());
        sort(walls.begin(),walls.end());

        vector<P> range(n);

        for(int i=0;i<n;i++){
            int pos=robodist[i].first;
            int d=robodist[i].second;

            int leftlimit=(i==0) ? 1: robodist[i-1].first+1;
            int rightlimit=(i==n-1)? 1e9: robodist[i+1].first-1;

            int l=max(pos-d,leftlimit);
            int r=min(pos+d,rightlimit);

            range[i]={l,r};

        }
        dp.assign(n+1,vector<int>(2,-1));
        // prev==0 means prev ele hit left if ==1 it hits right
        return slove(walls,range,robodist,0,0);
    }

    int slove(vector<int>& walls,vector<P> &range,vector<P> &robodist,int ind,int prev){
        if(ind==robodist.size())return 0;

        if(dp[ind][prev]!=-1)return dp[ind][prev];
        int leftmost=range[ind].first;
        if(prev==1){
            leftmost=max(range[ind-1].second+1,leftmost);
        }
        int left=countwalls(walls,leftmost,robodist[ind].first)+
                    slove(walls,range,robodist,ind+1,0);
        int right=countwalls(walls,robodist[ind].first,range[ind].second)+
                    slove(walls,range,robodist,ind+1,1);
        return dp[ind][prev]=max(left,right);

    }
    int countwalls(vector<int>& walls,int l,int r){
        int left=lower_bound(walls.begin(),walls.end(),l)-walls.begin();
        int right=upper_bound(walls.begin(),walls.end(),r)-walls.begin();
        return right-left;
    }
};