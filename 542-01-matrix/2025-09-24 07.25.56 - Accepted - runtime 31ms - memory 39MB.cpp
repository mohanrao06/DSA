class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }else{
                    vis[i][j]=0;
                }
            }
        }
        vector<vector<int>> dist(n,vector<int>(m,0));
        int drow[]={0,-1,0,+1};
        int dcol[]={-1,0,+1,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int d=q.front().second;
            q.pop();
            dist[r][c]=d;
            for(int i=0;i<4;i++){
                int nrow=drow[i]+r;
                int ncol=dcol[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]==1){
                    q.push({{nrow,ncol},d+1});
                    vis[nrow][ncol]=1;
                }
            }




        }
        return dist;


    }
};