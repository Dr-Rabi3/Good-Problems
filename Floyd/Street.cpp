// https://codeforces.com/gym/101147/problem/B



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
#define watch(...) cout << " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define Good_Bay return

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

constexpr int mod = 1e9 + 7, oo = 0x3f3f3f3f, N = 1e6 + 5;
const double pi = acos(-1), EPS = 1e-7;
constexpr ll OO = 0x3f3f3f3f3f3f3f3f;

constexpr int dy[] = { 0 , -1 , 0 , 1, 1 , -1 ,  1 , -1 };
constexpr int dx[] = { 1 , 0 , -1 , 0 , 1 , -1 , -1 ,  1 };
struct inp {
    double h, w, d, f;
};

void doWork(int tt) {
    int n, l, u;
    cin >> n >> l >> u;
    vector<vector<double>>cost(n + 2, vector<double>(n + 2, 1e18));
    vector<inp>v(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> v[i].h >> v[i].w >> v[i].d >> v[i].f;
        cost[0][i] = v[i].d;
        cost[i][n + 1] = l - (v[i].h + v[i].d);
    }
    cost[0][n + 1] = l;

    auto dist = [&](int i, int j)->double {
        if (v[i].f == v[j].f || v[i].w + v[j].w > u)
            return max(v[i].d, v[j].d) - min(v[i].d + v[i].h, v[j].h + v[j].d);
        if ((v[i].d >= v[j].d && v[i].d <= v[j].d + v[j].h) ||   // fot intersection and diff direction
            v[j].d >= v[i].d && v[j].d <= v[i].d + v[i].h)
            return u - (v[i].w + v[j].w);
        double y = max(v[i].d, v[j].d) - min(v[i].d + v[i].h, v[j].h + v[j].d);
        double x = u - (v[i].w + v[j].w);
        x *= x, y *= y;
        return sqrt(x + y);
    };

    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            cost[i][j] = (i == j ? 0 : dist(i, j));

    ++n;
    for (int k = 0;k <= n;k++)
        for (int i = 0;i <= n;i++)
            for (int j = 0;j <= n;j++)
                cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
    cout << fixed(9) << cost[0][n];
}

int main() {
    // freopen("street.in", "r", stdin);
    Accept();
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        cout << ed;
        // if (i < t)cout << ed;
    }
    Good_Bay 0;
}
