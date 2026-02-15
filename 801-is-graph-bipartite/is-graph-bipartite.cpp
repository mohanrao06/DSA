class Solution {
public:
    bool fun(vector<vector<int>>& graph,vector<int> &vis,int it){
        queue<pair<int,int>> q;
        q.push({it,1});
        vis[it]=1;
        while(!q.empty()){
            int node=q.front().first;
            int color=q.front().second;
            q.pop();
            for(auto it:graph[node]){
                if(!vis[it]){
                    vis[it]=color+1;
                    q.push({it,color+1});
                }else{
                    if(vis[it]==color)return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(!fun(graph,vis,i))return false;
            }
        }
        return true;
        
    }
};