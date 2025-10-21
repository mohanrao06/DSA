class DisjointSet{
    private:
        vector<int> parent,rank,size;
    public:
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
    int removeStones(vector<vector<int>>& stones) {
        int maxrows=0;
        int maxcol=0;
        for(auto it:stones){
            maxrows=max(maxrows,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DisjointSet ds(maxrows+maxcol+1);
        unordered_map<int,int> mp;


        for(auto it:stones){
            int u=it[0];
            int v=it[1]+maxrows+1;
            ds.unionByize(u,v);
            mp[u]=1;
            mp[v]=1;

        }
        int cnt=0;
        for(auto it:mp){
            if(ds.findParent(it.first)==it.first)cnt++;
        }
        return stones.size()-cnt;

    }
};