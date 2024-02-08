class Solution {
public:
    int numTilings(int n) {
        vector<int>dp(n + 5);
        dp[1] = 1;
        dp[2] = 2;
        long long a, b, c, d;
        a = b = c = d = 0;
        for (int i = 1;i <= n;i++) {
            a = dp[i];
            b = dp[i - 1];
            if (i > 2) {
                c = dp[i - 2];
                int j = i - 4;
                while (j > 0)c += dp[j], j -= 2;
            }
            if (i > 3) {
                d = dp[i - 3];
                int j = i - 5;
                while (j > 0)c += dp[j], j -= 2;
            }
            a %= 1000000007;
            b %= 1000000007;
            c *= 2;
            c %= 1000000007;
            d *= 2;
            d %= 1000000007;

            dp[i + 1] = (a + b + c + d) % (1000000007) ;
            /*
            w(a) = 1
            w(b) = 2;
            w(c) = 3 odd;
            w(d) = 4 even;
            An = Ana + Anb + 2Anc + 2And
               = A(n+1)a + A(n+1)b + 2A(n+1)c + 2A(n+1)d
            1- A(n+1)a = Ana
            2- A(n+1)b = A(n-1)b;
            3- A(n+1)c = A(n-2)c + A(n-4)c + ... + A1 | A0
            4- A(n+1)d = A(n-3)d + A(n-5)d + ... + A1 | A0
            A1 A2 A3 A4  A5 
            1  2  5  11  24
            */
        }
        return dp[n + 1];    
    }
};
