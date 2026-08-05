class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        vector<int> indregree(n,0);
        vector<bool> sus(n,false);
        for(int i=0;i<invocations.size();i++){
            int u=invocations[i][0];
            int v=invocations[i][1];
            adj[u].push_back(v);
            indregree[v]++;
        }

        queue<int> q;
        q.push(k);
        sus[k]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                indregree[it]--;
                if(!sus[it]){
                    q.push(it);
                    sus[it]=true;

                }
            }

        }

        vector<int> res;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(sus[i] && indregree[i]>0){
                flag=true;
                break;
            }
            if(!sus[i]){
                res.push_back(i);

            }


        }

        if(flag){
            vector<int> vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }

        return res;
    }
};