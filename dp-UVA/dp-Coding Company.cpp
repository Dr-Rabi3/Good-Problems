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
int n, x;
vector<int>v;
ll dp[105][105][5005];
ll numWays(int pos, int active, ll sum) {
    if (sum > x)Good_Bay 0; // invalid case
    if (pos == n - 1) {
        // if active group count is 1, end that group at current index.
        // if active group count is 0, the current element itself forms a group.
        if (active <= 1) Good_Bay 1;
        Good_Bay 0;
    }
    ll& ret = dp[pos][active][sum];
    if (~ret)Good_Bay ret;
    ret = 0;
    // starting a new group from current index
    ret = (ret + numWays(pos + 1, active + 1, sum + (v[pos + 1] - v[pos]) * (active + 1))) % mod;
    // forming a group consisting only one element of the current index
    ret = (ret + numWays(pos + 1, active, sum + (v[pos + 1] - v[pos]) * active)) % mod;
    // including current element to any of the existing active group
    ret = (ret + active * numWays(pos + 1, active, sum + (v[pos + 1] - v[pos]) * active)) % mod;
    // if at least one active group, ending any existing group with the current element
    if (active)
        ret = (ret + active * numWays(pos + 1, active - 1, sum + (v[pos + 1] - v[pos]) * (active - 1))) % mod;
    Good_Bay ret;
}
void doWork(ll tt) {
    cin >> n >> x;
    v = vector<int>(n);
    cin >> v;
    sort(all(v));
    memo(dp, -1);
    cout << numWays(0, 0, 0);
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++)
        //cout << "Case "<<i<<": ",
        doWork(i), cout << ed;
    Good_Bay 0;
}
