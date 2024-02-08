///  https://leetcode.com/problems/count-sub-islands/?envType=study-plan&id=graph-i


class Solution {
public:
    int dy[8] = { 1 , 0 , -1 ,  0 , 1 , -1 ,  1 , -1 };
    int dx[8] = { 0 , 1 ,  0 , -1 , 1 , -1 , -1 ,  1 };
    vector<vector<int>>island1;
    vector<vector<int>>island2;
    bool take = true;
    int n, m;
    bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
    void DFS(int nr, int nc) {
        island1[nr][nc] = 0;
        island2[nr][nc] = 0;
        for (int i = 0;i < 4;i++) {
            int x = nr + dx[i];
            int y = nc + dy[i];
            if (valid(x, y)) {
                if (island1[x][y] == 1 && island2[x][y] == 1)
                    DFS(x, y);
                else if (island2[x][y] == 1 && island1[x][y] == 0) {
                    take = false;
                    DFS(x, y);
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        island1 = grid1;
        island2 = grid2;
        int ans = 0;
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < m;j++) {
                if (island1[i][j] == 1 && island2[i][j] == 1) {
                    take = true;
                    DFS(i, j);
                    ans += (take == true);
                }
            }
        }
        return ans;
    }
};
