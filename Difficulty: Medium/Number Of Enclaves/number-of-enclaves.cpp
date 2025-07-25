class Solution {
public:
    int n, m;
    int dfs(int i, int j, bool& touch, vector<vector<int>>& g,
            vector<vector<int>>& vis) {
        vis[i][j] = 1;
        int cnt = 1;
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
            touch = true;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if (ni >= 0 && nj >= 0 && ni < n && nj < m && g[ni][nj] == 1 &&
                !vis[ni][nj])
                cnt += dfs(ni, nj, touch, g, vis);
        }
        return cnt;
    }
    int numberOfEnclaves(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (g[i][j] == 1 && !vis[i][j]) {
                    bool touch = false;
                    int cnt = dfs(i, j, touch, g, vis);
                    if (!touch)
                        ans += cnt;
                }
        return ans;
    }
};
