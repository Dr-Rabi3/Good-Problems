class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size(), m = k;
        vector<vector<int>>v = piles;
        int nn =0;
        for(auto i:piles){
            nn = max(nn,(int)(i.size()));
        }
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(nn + 10, vector<int>(m + 10, -1)));
        function<int(int, int, int)> MaxWallet = [&](int i, int j, int rem) {
            if (rem == 0) return 0;
            if (i == n)return (rem != 0 ? -1000006 : 0);
            if (~dp[i][j][rem]) return dp[i][j][rem];
            if (j < v[i].size()) {
                dp[i][j][rem] = max(dp[i][j][rem], v[i][j] + MaxWallet(i, j + 1, rem - 1));
            }
            dp[i][j][rem] = max(dp[i][j][rem], MaxWallet(i + 1, 0, rem));
            return dp[i][j][rem];
        };
        return MaxWallet(0, 0, m);
    }
};
