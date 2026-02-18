class DSU{
    private:
        vector<int> parent,size;
    public:
        DSU(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        int findParent(int i){
            if(i==parent[i])return i;
           return parent[i]=findParent(parent[i]);
        }
        void Union(int u,int v){
            int pu=parent[u];
            int pv=parent[v];
            if(size[pu]>=size[pv]){
                parent[pv]=pu;
                size[pu]+=size[pv];
            }else{
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DSU dsu(n);
        int extra=0;
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            if(dsu.findParent(u)==dsu.findParent(v))extra++;
            else{
                dsu.Union(u,v);
            }
        }
        int comp=0;
        for(int i=0;i<n;i++){
            if(dsu.findParent(i)==i){
                comp++;
            }
        }
        comp=comp-1;
        if(comp<=extra){
            return comp;
        }
        return -1;
    }
};