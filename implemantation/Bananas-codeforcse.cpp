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
#define     sumOf(a)                 (ll)((-1 + sqrt(8 * a + 1)) / 2)
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
void doWork(ll tt) {
    ll n, m;
    cin >> n >> m;// 400 50
    ll l = 1, r = m, ans = 1;
    while (l <= r) {
        ll mid = (l + r) >> 1; // 3
        ll sum = 0;
        ll a = m / mid;// 50/3 = 16 -> 16 monkey every 3 monkey will take the same number
        ll b = m % mid;// 50%3 = 2 -> 2 monkey must take number not take before is 17
        sum += a * (a + 1);
        sum /= 2;
        sum *= mid;// 1 1 1 / 2 2 2 / 3 3 3 / 4 4 4 / ... / 16 16 16 = 408
        sum += b * (a + 1);// number remmaber monkey not take yat and will take 17 17 (a+1) * b
        ( sum <= n ? r = mid - 1, ans = mid : l = mid + 1); // total sum =  442
    }
    cout << ans;
}
int main() {
    Accept();
    int t = 1;
    cin >> t;
    for (int i = 1;i <= t;i++)
        //cout << "Case "<<i<<": ",
        doWork(i), cout << ed;
    Good_Bay 0;
}
