class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        pq.push({grid[0][0],0,0});
        int dr[]={0,-1,0,1};
        int dc[]={1,0,-1,0};
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int elv=temp[0];
            int r=temp[1];
            int c=temp[2];

            if(r==n-1 && c==n-1)return elv;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n &&nc>=0 && nc<n && !vis[nr][nc]){
                    pq.push({max(elv,grid[nr][nc]),nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return -1;
    }
};