#include<bits/stdc++.h>
using namespace std;

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
    bool isVaild(int row,int col,int n,int m){
      return row>=0 && row<n && col>=0 && col<m ;
  }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0)continue;

                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int in=0;in<4;in++){
                    int nr=i+dr[in];
                    int nc=j+dc[in];

                    if(isVaild(nr,nc,n,n) && grid[nr][nc]==1){
                        int n1=i*n+j;
                        int n2=nr*n+nc;
                        ds.unionByize(n1,n2);

                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)continue;
                set<int> comp;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int in=0;in<4;in++){
                    int nr=i+dr[in];
                    int nc=j+dc[in];

                    if(isVaild(nr,nc,n,n) && grid[nr][nc]==1){
                        int n2=nr*n+nc;
                        comp.insert(ds.findParent(n2));

                    }
                }
                int totalSize=0;
                for(int it:comp){
                    totalSize+=ds.size[it];
                }
                mx=max(mx,totalSize+1);

            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findParent(i)]);
        }
        return mx;

    }
};