class Solution {
public:
    #define memo(dp,x) memset(dp,x,sizeof(dp))
    int n;
    vector<int>v;
    int dp[5005][2];
    int MaxProfit(int i, int last) {
        if (i >= n)return 0;
        int& ret = dp[i][last];
        if (~ret) return ret;
        int ans = -1e9;
        if (last) {
            ans = max(ans, MaxProfit(i + 1, 0) - v[i]);
            ans = max(ans, MaxProfit(i + 1, 1));
        }
        else {
            ans = max(ans, MaxProfit(i + 2, 1) + v[i]);
            ans = max(ans, MaxProfit(i + 1, 0));
        }
        return ret = ans;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        v = prices;
        memo(dp, -1);
        return MaxProfit(0,1);
    }
};
