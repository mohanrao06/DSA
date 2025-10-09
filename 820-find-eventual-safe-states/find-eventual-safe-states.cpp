class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        vector<int> outdeg(n);
        for(int i=0;i<n;i++){
            for(int it:graph[i]){
                adj[it].push_back(i);
                outdeg[i]++;
            }
        }
       
        
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(outdeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(int it:adj[top]){
                outdeg[it]--;
                if(outdeg[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};