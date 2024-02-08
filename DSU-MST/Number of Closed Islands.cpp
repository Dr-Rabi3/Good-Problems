/// https://leetcode.com/problems/number-of-closed-islands/?envType=study-plan&id=graph-i


class Solution {
public:
    int dy[8] = { 1 , 0 , -1 ,  0 , 1 , -1 ,  1 , -1 };
    int dx[8] = { 0 , 1 ,  0 , -1 , 1 , -1 , -1 ,  1 };
    vector<vector<pair<int,pair<int, int>>>>par;
    int siz[200][200];
    void init(int n, int m) {
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++){
                bool ok = 1;
                if ((i == 1 || i == n || j == 1 || j == m))ok = 0;
                par[i][j] = { ok,{i,j} },
                siz[i][j] = 1;

            }
    }
    pair<int, int>FindPar(pair<int, int>u) {
        return (par[u.first][u.second].second == make_pair(u.first, u.second) ? u : FindPar(par[u.first][u.second].second));
    }
    void Con(int ok, pair<int, int>u, pair<int, int>v) {
        u = FindPar(u);
        v = FindPar(v);
        if (u == v)return;
        if (siz[u.first][u.second] < siz[v.first][v.second])swap(u, v);
        siz[u.first][u.second] += siz[v.first][v.second];
        par[v.first][v.second].second = par[u.first][u.second].second;
        par[u.first][u.second].first &= par[v.first][v.second].first;
        par[u.first][u.second].first &= ok;
        par[v.first][v.second].first = par[u.first][u.second].first;
    }
    int closedIsland(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        par = vector<vector<pair<int, pair<int, int>>>>(n + 1, vector<pair<int, pair<int, int>>>(m + 1));
        init(n, m);
        int NoIsland = 0;
        vector<vector<int>>grid(n + 1, vector<int>(m + 1));
        for (int i = 1;i <= n;i++)for (int j = 1;j <= m;j++)grid[i][j] = g[i - 1][j - 1];
        for (int i = 1;i <= n;i++) {
            for (int j = 1;j <= m;j++) {
                if (grid[i][j] == 0) {
                    bool ok = 1;
                    for (int k = 0;k < 4;k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x > 0 && x <= n && y > 0 && y <= m && grid[x][y] == 0) {
                            if ((x == 1 || x == n || y == 1 || y == m))ok = 0;
                            Con(ok, { i,j }, { x,y });
                        }
                    }
                }
                else siz[i][j] = 0;
            }
        }
        set<pair<int, int>>st;
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= m;j++)
                if (grid[i][j] == 0) {
                    pair<int, int> p = FindPar({ i,j });
                    if (par[p.first][p.second].first && i > 1 && i < n && j > 1 && j < m) {
                        st.insert(p);
                    }
                }
        return st.size();
    }
};
