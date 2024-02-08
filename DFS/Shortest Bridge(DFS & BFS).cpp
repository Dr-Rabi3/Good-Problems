/// https://leetcode.com/problems/shortest-bridge/description/?envType=study-plan&id=graph-i


class Solution {
public:
    int dy[8] = { 1 , 0 , -1 ,  0 , 1 , -1 ,  1 , -1 };
    int dx[8] = { 0 , 1 ,  0 , -1 , 1 , -1 , -1 ,  1 };
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    void DFS(int nr, int nc, vector<vector<int>>& grid, vector<vector<int>>& dist, queue<pair<int, int>>& q) {
        grid[nr][nc] = 2;
        dist[nr][nc] = 0;
        int n = grid.size(), m = grid[0].size();
        q.push({ nr,nc });
        for (int i = 0;i < 4;i++) {
            int x = nr + dx[i];
            int y = nc + dy[i];
            if (valid(x, y, n, m) && grid[x][y] == 1)
                DFS(x, y, grid, dist, q);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {    
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>dist(n, vector<int>(m, -1));
        for (int i = 0;i < n;i++) {
            bool ok = 0;
            for (int j = 0;j < m;j++)
                if (grid[i][j] == 1) {
                    DFS(i, j, grid, dist, q);
                    ok = 1;
                    break;
                }
            if (ok)break;
        }
        int ans = 0;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            if (grid[x][y] == 1) {
                ans = dist[x][y];
                break;
            }
            q.pop();
            for (int i = 0;i < 4;i++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (valid(xx, yy, n, m) && dist[xx][yy] == -1) {
                    q.push({ xx,yy });
                    dist[xx][yy] = dist[x][y] + (grid[xx][yy] == 0);
                }
            }
        }
        return ans;
    }
};
