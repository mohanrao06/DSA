class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(arr[node]==0)return true;
            int ele=arr[node];
            if(node+ele<n && !vis[node+ele]){
                q.push(node+ele);
                vis[node+ele]=1;
            }
            if(node-ele>=0 && !vis[node-ele]){
                q.push(node-ele);
                vis[node-ele]=1;
            }
        }
        return false;
    }
};