///  https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=study-plan&id=graph-i



class Solution {
public:
    int m, n;
    std::vector<std::vector<bool>> m_atlantic, m_pacific;
    std::vector<std::vector<int>> m_answer;

    vector<vector<int> > pacificAtlantic(vector<vector<int>>& mat) {
        m = size(mat), n = size(mat[0]);
        m_atlantic = m_pacific = std::vector<std::vector<bool>>(m, std::vector<bool>(n));

        for(int i = 0; i < m; i++) dfs(mat, m_pacific, i, 0), dfs(mat, m_atlantic, i, n - 1);
        for(int i = 0; i < n; i++) dfs(mat, m_pacific, 0, i), dfs(mat, m_atlantic, m - 1, i);
        return m_answer;
    }
    void dfs(std::vector<std::vector<int>>& mat, std::vector<std::vector<bool>>& visited, int i, int j){
        if(visited[i][j]) return;
        visited[i][j] = 1;

        if(m_atlantic[i][j] && m_pacific[i][j]) m_answer.push_back(std::vector<int>{i, j});

        if(i + 1 <  m && mat[i + 1][j] >= mat[i][j]) dfs(mat, visited, i + 1, j);
        if(i - 1 >= 0 && mat[i - 1][j] >= mat[i][j]) dfs(mat, visited, i - 1, j);
        if(j + 1 <  n && mat[i][j + 1] >= mat[i][j]) dfs(mat, visited, i, j + 1);
        if(j - 1 >= 0 && mat[i][j - 1] >= mat[i][j]) dfs(mat, visited, i, j - 1);
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool valid(int& i, int& j, int n, int m) { return i >= 0 && i < n && j >= 0 && j < m; }
    bool DFS(int sr, int sc, vector<vector<bool>>& oc, vector<vector<int>>& gird) {
        if (!valid(sr, sc, gird.size(), gird[0].size()) || gird[sr][sc] == -1)return false;
        if (oc[sr][sc])return true;
        int x = gird[sr][sc];
        gird[sr][sc] = -1;
        bool ok = 0;
        ok |= (sr > 0 && x >= gird[sr - 1][sc]) && DFS(sr - 1, sc, oc, gird);
        ok |= (sr + 1 < gird.size() && x >= gird[sr + 1][sc]) && DFS(sr + 1, sc, oc, gird);
        ok |= (sc > 0 && x >= gird[sr][sc - 1]) && DFS(sr, sc - 1, oc, gird);
        ok |= (sc + 1 < gird[0].size() && x >= gird[sr][sc + 1]) && DFS(sr, sc + 1, oc, gird);
        oc[sr][sc] = ok;
        gird[sr][sc] = x;
        return ok;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>>pac(n, vector<bool>(m)), atl(n, vector<bool>(m));
        for (int i = 0;i < n;i++)
            pac[i][0] = atl[i][m - 1] = true;
        for (int j = 0;j < m;j++)
            pac[0][j] = atl[n - 1][j] = true;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (DFS(i, j, pac, grid) && DFS(i, j, atl, grid))
                    ans.push_back({ i,j });
        return ans;
    }
};


