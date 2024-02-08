/// https://vjudge.net/problem/UVA-11404

/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define ed '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fixed(x) fixed<<setprecision(x)
#define memo(dp,x) memset(dp,x,sizeof(dp))
#define sumOf(a) (ll)((-1 + sqrt(8 * a + 1)) / 2)
#define watch(x) cout << #x << " = { " << x << " }\n";
#define Good_Bay return

constexpr int mod = 1e9 + 7, oo = 0x3f3f3f3f, N = 1e6 + 5;
const double pi = acos(-1), EPS = 1e-7;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;
using namespace std;
using namespace __gnu_pbds;

template < typename T > struct ordered_set {
    tree< T, null_type, less< T >, rb_tree_tag, tree_order_statistics_node_update > ost;
};
template < typename T > istream& operator >> (istream& in, vector < T >& v) {
    for (auto& x : v) in >> x;
    return in;
}

template < typename T > ostream& operator << (ostream& out, const vector < T >& v) {
    for (const T& x : v) out << x << ' ';
    return out;
}

void Accept() { // for VS code
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int dy[] = { 0 , -1 , 0 , 1, 1 , -1 ,  1 , -1 };
int dx[] = { 1 , 0 , -1 , 0 , 1 , -1 , -1 ,  1 };
int dp[2000][2000];
int n;
string s;
int DP(int l, int r) {
    if (l >= r)return r == l;
    if (~dp[l][r])return dp[l][r];
    if (s[l] == s[r])return dp[l][r] = DP(l + 1, r - 1) + 2;
    return dp[l][r] = max(DP(l + 1, r), DP(l, r - 1));
}
string mem[2000][2000];
string rec(int l, int r) {
    if (l > r)return "";
    if (l == r) return string(1, s[l]);
    if (mem[l][r] != "")return mem[l][r];
    int op1 = DP(l + 1, r);
    int op2 = DP(l, r - 1);
    int opt = DP(l, r);
    if (s[l] == s[r]) {
        return mem[l][r] = string(1,s[l]) + rec(l + 1, r - 1) + string(1,s[r]);
    }
    else {
        if (op1 == opt && op2 == opt)return mem[l][r] = min(rec(l + 1, r), rec(l, r - 1));
        else if (op1 < op2) return mem[l][r] = rec(l, r - 1);
        return mem[l][r] = rec(l + 1, r);
    }

}
void doWork(int tt) {
    while (cin >> s) {
        n = s.size();
        for (int i = 0;i < n;i++)
            for (int j = 0;j < n;j++)
                dp[i][j] = -1, mem[i][j] = "";
        int ans = DP(0, n - 1);
        // cout << ans << ed;
        cout << rec(0, n - 1) << ed;
    }
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        //cout << ed;
        // if (i < t)cout << ed;
    }
    Good_Bay 0;
}
