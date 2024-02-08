/// https://codeforces.com/contest/1473/problem/E

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

constexpr int mod = 1e9 + 7, oo = 0x3f3f3f3f, N = 2e5 + 5;
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
void doWork(int tt) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>>adj[n + 1];
    for (int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
        adj[v].push_back({ u,w });
    }
    vector<vector<vector<ll>>>dist(n + 1, vector<vector<ll>>(2, vector<ll>(2, OO)));
    priority_queue<pair<ll, array<int, 3>>, vector<pair<ll, array<int, 3>>>, greater<>>pq;
    pq.push({ 0,{1,0,0} });
    dist[1][0][0] = 0;
    while (!pq.empty()) {
        int node, mx, mn;
        ll cost;
        tie(cost, node, mx, mn) = tie(pq.top().first, pq.top().second[0], pq.top().second[1], pq.top().second[2]);
        pq.pop();
        if (dist[node][mx][mn] < cost)continue;
        for (auto i : adj[node]) {
            ll newCost = cost + i.second;
            if (newCost < dist[i.first][mx][mn]) {
                dist[i.first][mx][mn] = newCost;
                pq.push({ newCost,{i.first,mx,mn} });
            }
            // not take mx in path, than try to take this wight to be max
            // use cost only, because we subtract mx from all sum that must contain this wight to like 10 + 2 - 2, here we will add wight of this edge and consider it max than will subtract it. ^^
            if (!mx and dist[i.first][1][mn] > cost) {
                dist[i.first][1][mn] = cost;
                pq.push({ cost,{i.first,1,mn} });
            }
            // not take mx in path, than try to take this wight to be max
            // use cost + 2 * i.second, because we add mn to all sum that contain mn too, like 10 + 2 + 2, here that wight add for path and add because it is mn too.
            if (!mn and dist[i.first][mx][1] > cost + 2 * i.second) {
                dist[i.first][mx][1] = cost + 2 * i.second;
                pq.push({ cost + 2 * i.second,{i.first,mx,1} });
            }
            // not take mx and mn in path, than try to take this wight to be max and mn
            // use cost + i.second, because we subtract mx and add mn to all sum, that contain mn and mx, but it's the same number now for that add one, like 10 + 2 - 2(mx) + 2(mn) = 10 + 2. ^^
            if (!mx && !mn && dist[i.first][1][1] > cost + i.second) {
                dist[i.first][1][1] = cost + i.second;
                pq.push({ cost + i.second,{i.first,1,1} });
            }
        }
    }
    for (int i = 2;i <= n;i++)cout << dist[i][1][1] << ' ';
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++) {
        // cout << "Case "<<i<<": ",
        doWork(i);
        cout << ed;
        // if (i < t)cout << ed;
    }
    Good_Bay 0;
}
