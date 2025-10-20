class DisjointSet{
    
        
    public:
    vector<int> parent,rank,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int node){
        if(node==parent[node])return node;
        return parent[node]=findParent(parent[node]);

    }

    void unionByRank(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pv]<rank[pu]){
            parent[pv]=pu;
        }
        else{
            parent[pu]=pv;
            rank[pu]++;
        }
    }
    void unionByize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v)){
                extra++;
            }else{
                ds.unionByize(u,v);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)ans++;
        }
        ans=ans-1;
        if(ans<=extra){
            return ans;
        }
        return -1;
    }
};