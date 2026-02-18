// User function Template for C++
class  DSU{
    private:
        vector<int> parent;
        vector<int> size;
    public:
        DSU(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        
        void merge(int u,int v){
            int pu=findparent(u);
            int pv=findparent(v);
            if(pu!=pv){
                if(size[pu]>=size[pv]){
                    parent[pv]=pu;
                    size[pu]+=size[pv];
                }else{
                    parent[pu]=pv;
                    size[pv]+=size[pu];
                }
            }
        }
        int findparent(int i){
            if(i==parent[i])return i;
            return parent[i]=findparent(parent[i]);
        }
};
    

class Solution {
public:
    static bool comparator(vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    }
    int kruskalsMST(int V, vector<vector<int>> edges,int include,int exclude) {
        // code here
        DSU dsu(V);
        int sum=0;
        int countedges=0;
        if(include!=-1){
            int u=edges[include][0];
            int v=edges[include][1];
            int wt=edges[include][2];
            int edge=edges[include][3];
            if(dsu.findparent(u)!=dsu.findparent(v)){
                dsu.merge(u,v);
                sum+=wt;
                countedges++;
            }
        }
        for(int i=0;i<edges.size();i++){
                if(i==exclude)continue;
                int u=edges[i][0];
                int v=edges[i][1];
                int wt=edges[i][2];
                int edge=edges[i][3];   
                if(dsu.findparent(u)!=dsu.findparent(v)){
                    dsu.merge(u,v);
                    sum+=wt;
                    countedges++;
                }            
        }
        if(countedges==V-1)return sum;
        return INT_MAX;
        
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<vector<int>> newarr;
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            newarr.push_back({u,v,wt,i});
        }
        sort(newarr.begin(), newarr.end(), comparator);
        int base=kruskalsMST(n,newarr,-1,-1);
        vector<int> critical;
        vector<int> pseudo;
        for(int i=0;i<edges.size();i++){
           int costWithout=kruskalsMST(n,newarr,-1,i);
           if(costWithout>base){
                critical.push_back(newarr[i][3]);
           }else{
                int costwith=kruskalsMST(n,newarr,i,-1);
                if(base==costwith){
                    pseudo.push_back(newarr[i][3]);
                }
           }
        }
        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo);
        return ans;
    }
};