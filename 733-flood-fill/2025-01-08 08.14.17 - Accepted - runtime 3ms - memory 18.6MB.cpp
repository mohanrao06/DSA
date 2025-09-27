class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>> &vis,vector<vector<int>> image,int color,int drow[],int dcol[],int init){
        vis[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();

        for(int i=0;i<4;i++){
            int nrow = drow[i]+sr;
            int ncol=dcol[i]+sc;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != color && image[nrow][ncol]==init){
                dfs(nrow,ncol,vis,image,color,drow,dcol,init);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int init=image[sr][sc];
        vector<vector<int>> vis=image;
        int drow[]={-1,0,1,0};
        int dcol[]={0,1,0,-1};
        dfs(sr,sc,vis,image,color,drow,dcol,init);
        return vis;
        
    }
};