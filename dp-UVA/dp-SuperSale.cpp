/*** وَمَا تَوْفِيقِي إِلَّا بِاللَّهِ ۚ عَلَيْهِ تَوَكَّلْتُ وَإِلَيْهِ أُنِيبُ ***/

#include                             <bits/stdc++.h>
#define     ll                       long long
#define     ld                       long double
#define     ft                       first
#define     sd                       second
#define     ed                       '\n'
#define     sz(x)                    x.size()
#define     all(x)                   x.begin(), x.end()
#define     rall(x)                  x.rbegin(), x.rend()
#define     fixed(x)                 fixed<<setprecision(x)
#define     memo(dp,x)               memset(dp,x,sizeof(dp))
#define     mod                      1'000'000'007
#define     OO                       2'000'000'000
#define     EPS                      1e-7
#define     pi                       acos(-1)
#define     Good_Bay                 return 
using namespace std;

template < typename T = int > istream& operator >> (istream& in, vector < T >& v) {
    for (auto& x : v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream& out, const vector < T >& v) {
    for (const T& x : v) out << x << ' ';
    return out;
}
void Accept() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int dx[] = { -1 ,  0 ,  1 , 1 , 1 , 0 , -1 , -1 };
int dy[] = { -1 , -1 , -1 , 0 , 1 , 1 ,  1 ,  0 };
int n, Max = int(-1e9);
vector<int>P, W;
vector<vector<int>>dp;
ll maxGoods(int i, int rem) {
    if (rem < 0)Good_Bay Max ;
    if (i == n)Good_Bay 0;
    int& ret = dp[i][rem];
    if (~ret)Good_Bay ret;
    Good_Bay ret = max(maxGoods(i + 1, rem), maxGoods(i + 1, rem - W[i]) + P[i]);
}
void doWork(ll tt) {
    cin >> n;
    P = vector<int>(n);
    W = vector<int>(n);
    for (int i = 0;i < n;i++)cin >> P[i] >> W[i];
    int q, x;
    cin >> q;
    ll sum = 0;
    while (q--) {
        cin >> x;
        dp.assign(n + 10, vector<int>(x + 10, -1));
        sum += maxGoods(0, x);
    }
    cout << sum;
}
int main() {
    Accept();
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++)
        // cout << "Case "<<i<<":\n",
        doWork(i), cout << ed;
    Good_Bay 0;
}
