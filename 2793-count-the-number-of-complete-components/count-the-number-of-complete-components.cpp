class Solution {
public:
    class DSU{
        public:
        vector<int> parent;
        vector<int> size;

        DSU(int n){
            parent.resize(n);
            size.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                size[i]=1;
            }
        }
        int find(int x){
            if(parent[x]==x)return x;
            return parent[x]=find(parent[x]);
        }
        void Union(int u,int v){
            int up=find(u);
            int vp=find(v);
            if(up==vp){
                return;
            }

            if(size[up]>size[vp]){
                parent[vp]=up;
                size[up]+=size[vp];
            }else if(size[up]<size[vp]){
                parent[up]=vp;
                size[vp]+=size[up];
            }else{
                parent[vp]=up;
                size[up]+=size[vp];
            }
        }



    };
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int,int> mp;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            dsu.Union(u,v);
        }

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int root=dsu.find(u);
            mp[root]++;
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dsu.find(i)==i){
                int v=dsu.size[i];
                int e=mp[i];
                if((v*(v-1))/2==e)res++;
            }
        }
        return res;
    }
};