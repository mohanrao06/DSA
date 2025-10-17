class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector(n, 10001));
        for (auto& e : edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        for(int i=0;i<n;i++)
            dis[i][i]=0;
        
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        int ans=0;
        int small=n;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<=small){
                ans=i;
                small=cnt;
            }
        }
        return ans;
        

        
    }
};