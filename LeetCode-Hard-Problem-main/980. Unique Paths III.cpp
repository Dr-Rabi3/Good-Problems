class Solution {
public:
    int n, m ,empty = 0;
    pair<int, int> start, end;
    vector<vector<int>> grid,visited;
    bool is_valid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m && !visited[i][j] && grid[i][j] != -1;
    }
    int ALL() {
        int cnt = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                cnt += visited[i][j];
        return cnt == empty + 1; // + 1 because it count start in visited array
    }
    int NumOfPaths(int i, int j) {
        if (!is_valid(i, j))return 0;
        if (i == end.first && j == end.second) return (ALL() ? 1 : 0);
        visited[i][j] = 1;
        int ans = 0;
        ans += NumOfPaths(i + 1, j);
        ans += NumOfPaths(i, j + 1);
        ans += NumOfPaths(i - 1, j);
        ans += NumOfPaths(i, j - 1);
        visited[i][j] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid2) {
        grid = grid2;
        n = grid.size(), m = grid[0].size();
        visited = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (grid[i][j] == 1)start.first = i, start.second = j;
                else if (grid[i][j] == 2) end.first = i, end.second = j;
                else if (grid[i][j] == 0) empty++;
        return NumOfPaths(start.first, start.second);
    }
};
