class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int, vector<pair<int, int>>> directions = {
            {1, {{0, -1}, {0, 1}}},   // Left, Right
            {2, {{-1, 0}, {1, 0}}},   // Up, Down
            {3, {{0, -1}, {1, 0}}},   // Left, Down
            {4, {{0, 1}, {1, 0}}},    // Right, Down
            {5, {{0, -1}, {-1, 0}}},  // Left, Up
            {6, {{0, 1}, {-1, 0}}}    // Right, Up
        };

        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>>vis (n,vector<int>(m,0));
        vis[0][0]=1;
        q.push({grid[0][0],{0,0}});
        while(!q.empty()){
            int val=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            if(r==n-1 && c==m-1)return true;
            vector<pair<int, int>> del=directions[val];
            for(int i=0;i<2;i++){
                int nr=r+del[i].first;
                int nc=c+del[i].second;
                if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc]){
                     for(auto &back : directions[grid[nr][nc]]){
                        if(nr + back.first == r && nc + back.second == c){
                            vis[nr][nc] = 1;
                            q.push({grid[nr][nc], {nr, nc}});
                        }
                    }
                }
            }
        }
        return false;

    }
};