class Solution {
public:
    int dp[100];
    int numTrees(int n) {
        if(n <= 1) return 1;
        if(dp[n])return dp[n];
        int ans = 0;
        for(int i = 1; i <= n; i++) 
            ans += numTrees(i-1) * numTrees(n-i);
        return dp[n] =  ans;
    }
};
