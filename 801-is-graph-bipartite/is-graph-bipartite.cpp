class Solution {
public:
    bool dfs(int start,int c,vector<int>&col,vector<vector<int>>& graph,int n){
        col[start]=c;
        for(int it:graph[start]){
            if(col[it]==-1){
                if(dfs(it,!c,col,graph,n)==false)return false;
            }else if(col[it]==col[start])return false;
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       
        int n=graph.size();
        vector<int> col(n,-1);
       
        for(int i=0;i<n;i++){
            if(col[i]==-1){
            if(dfs(i,0,col,graph,n)==false)return false;
            }
        }
        return true;
       
    }
};