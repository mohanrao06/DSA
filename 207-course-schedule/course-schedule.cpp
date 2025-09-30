class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inorder(numCourses,0);
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[u].push_back(v);
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
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(int it:adj[node]){
                inorder[it]--;
                if(inorder[it]==0)q.push(it);
            }

        }
        if(cnt==inorder.size())return true;
        return false;
        

    }
};