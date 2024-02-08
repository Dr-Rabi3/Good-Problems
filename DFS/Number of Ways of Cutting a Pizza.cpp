/// https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza/description/


class Solution {
public:
    vector<vector<int>> PreFixSum2D(vector<string>& pizza){
        int n = pizza.size(), m = pizza[0].size();
        vector<vector<int>> prefix(n + 1, vector<int>(m + 1));
        for(int i = n - 1;i >= 0;i--)
            for(int j = m - 1;j >= 0;j--)
                prefix[i][j] += prefix[i + 1][j] + prefix[i][j + 1] - prefix[i + 1][j + 1] + (pizza[i][j] == 'A');
        return prefix;
    }
    int DFS(int sr, int sc, int n, int m, int k, vector<vector<vector<int>>>&dp, vector<vector<int>>&prefixSum){
        if(prefixSum[sr][sc] == 0) return 0;
        if(k == 0) return 1;
        if(~dp[sr][sc][k]) return dp[sr][sc][k];
        int ans = 0;
        for(int i = sr + 1;i < n;i++){
            if(prefixSum[sr][sc] - prefixSum[i][sc] > 0)
                ans += DFS(i, sc, n, m, k - 1, dp, prefixSum),
                ans %= 1000000007;
        }
        for(int j = sc + 1;j < m;j++){
            if(prefixSum[sr][sc] - prefixSum[sr][j] > 0)
                ans += DFS(sr, j, n, m, k - 1, dp, prefixSum),
                ans %= 1000000007;
        }
        return dp[sr][sc][k] = ans;
    }
    int ways(vector<string>& pizza, int k) {
        if(k <= 1)return k;
        int n = pizza.size(), m = pizza[0].size();
        vector<vector<int>> prefix = PreFixSum2D(pizza);
        vector<vector<vector<int>>>dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
        return DFS(0, 0, n, m, k - 1, dp, prefix);
    }
};
