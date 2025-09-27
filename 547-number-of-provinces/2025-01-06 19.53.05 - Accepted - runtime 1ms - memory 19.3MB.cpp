class Solution {
public:
    void dfs(int src,vector<int> &vis,vector<vector<int>>& isConnected){
        vis[src]=1;
        for(int i=0;i<isConnected[src].size();i++){
             if (isConnected[src][i] == 1 && !vis[i]) {
            dfs(i, vis, isConnected);
        }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n=isConnected.size();
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,isConnected);
                
            }
        }
        return count;
    }
};