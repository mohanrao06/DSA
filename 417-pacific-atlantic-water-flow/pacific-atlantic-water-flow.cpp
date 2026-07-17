class Solution {
public:
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    void dfs(int r, int c, vector<vector<int>>& heights,vector<vector<int>>& vis) {

        int n = heights.size();
        int m = heights[0].size();

        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {

                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            if (!pacific[0][j])
                dfs(0, j, heights, pacific);
        }


        for (int i = 0; i < n; i++) {
            if (!pacific[i][0])
                dfs(i, 0, heights, pacific);
        }

        for (int j = 0; j < m; j++) {
            if (!atlantic[n - 1][j])
                dfs(n - 1, j, heights, atlantic);
        }

        for (int i = 0; i < n; i++) {
            if (!atlantic[i][m - 1])
                dfs(i, m - 1, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};