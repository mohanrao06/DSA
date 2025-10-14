class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
        if(n==1)return 1;


        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        dist[0][0]=0;
        while(!q.empty()){
            int wt=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nr=r+dirs[i].first;
                int nc=c+dirs[i].second;
                if(nr>=0 && nr<n && nc>=0 && nc<n &&
                grid[nr][nc]==0 && wt+1<dist[nr][nc]){
                    dist[nr][nc]=wt+1;
                    q.push({wt+1,{nr,nc}});
                }
                
            }
        }
        if(dist[n-1][n-1]==INT_MAX)return  -1;
        return dist[n-1][n-1];
    }
};