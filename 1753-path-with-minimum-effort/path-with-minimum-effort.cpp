class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});
        dist[0][0]=0;
        int delcol[]={-1,0,+1,0};
        int delrow[]={0,-1,0,+1};
        while(!pq.empty()){
            auto node=pq.top();
            
            int wt=node.first;
            int r=node.second.first;
            int c=node.second.second;
            pq.pop();
            if (wt > dist[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m)
                {
                    int diff=abs(heights[r][c]-heights[nr][nc]);
                    int neweffort=max(wt,diff);
                if(neweffort<dist[nr][nc]){
                    dist[nr][nc]=neweffort;
                    pq.push({neweffort,{nr,nc}});
                }
                }
            }

        }
        return dist[n-1][m-1];


    }
};