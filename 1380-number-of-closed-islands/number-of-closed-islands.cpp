class Solution {
public:
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    int n = 0, m = 0;

    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + delrow[i];
            int nc = c + delcol[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                && vis[nr][nc] == 0 && grid[nr][nc] == 0)
                dfs(nr, nc, grid, vis);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++)                      // top
            if (grid[0][j] == 0) dfs(0, j, grid, vis);
        for (int i = 1; i < n; i++)                      // right
            if (grid[i][m-1] == 0) dfs(i, m-1, grid, vis);
        if (n > 1)                                       // bottom
            for (int j = m-2; j >= 0; j--)
                if (grid[n-1][j] == 0) dfs(n-1, j, grid, vis);
        if (m > 1)                                       // left
            for (int i = n-2; i > 0; i--)
                if (grid[i][0] == 0) dfs(i, 0, grid, vis);

        // water = visited, so only closed land stays 0
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) vis[i][j] = 1;

        vector<vector<int>> vis2(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (vis[i][j] == 0 && vis2[i][j] == 0) {
                    dfs(i, j, vis, vis2);
                    cnt++;
                }
        return cnt;
    }
};