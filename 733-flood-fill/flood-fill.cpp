class Solution {
public:
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color,int start,vector<vector<int>>&vis){
        vis[sr][sc]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+delrow[i];
            int ncol=sc+delcol[i];
            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && vis[nrow][ncol]!=color && image[nrow][ncol]==start){
                dfs(image,nrow,ncol,color,start,vis);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis=image;
        int start=image[sr][sc];

        dfs(image,sr,sc,color,start,vis);
        return vis;
    }
};