class Solution {
public:
    bool fun(vector<vector<int>>& graph,vector<int> &col,int node,int color){
        col[node]=color;
        for(auto it:graph[node]){
            if(col[it]==-1){
                if(fun(graph,col,it,!color)==false)return false;
            }else{
                if(col[it]==col[node])return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(!fun(graph,col,i,0))return false;
            }
        }
        return true;
        
    }
};