class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses,0);
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++){
            for(int it:adj[i]){
                inorder[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0)q.push(it);
            }

        }
        if(ans.size()==inorder.size())return ans;
        return {};
    }
};