class Solution {
public:
    void dfs(int sr, int sc, int color,vector<vector<int>> &vis,vector<vector<int>> image,int drow[],int dcol[],int init){
        vis[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=drow[i]+sr;
            int ncol=dcol[i]+sc;
            if(nrow>=0 && nrow<n & ncol>=0 && ncol<m && vis[nrow][ncol]!=color && image[nrow][ncol]==init){
                dfs(nrow,ncol,color,vis,image,drow,dcol,init);
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> vis=image;
        int init=image[sr][sc];
        int drow[]={0,-1,0,+1};
        int dcol[]={-1,0,+1,0};
        dfs(sr,sc,color,vis,image,drow,dcol,init);
        return vis;
    }
};