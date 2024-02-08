//   https://codeforces.com/group/u3Ii79X3NY/contest/274952/problem/H


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
#define     Good_Bay                 return

const int mod = 1000000007, OO = 2e9, EPS = 1e-7;
const double pi = acos(-1);

using namespace std;

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

int dxy[9][2] = { {-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{0,1},{-1,1},{-1,0} };

int mul_inv(int a, int b) { // don't forget it (Puiple(-40))
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}
void doWork(ll tt) {
    int n;
    cin >> n;
    int bits[10];
    for (auto& i : bits)i = 2;// with change
    while (n--) {
        /**
         *
         * x = 3 -> | 2222222211
         * x = 2 -> ^ 2222222201
         * x = 1 -> | 2222222201
        */
        char c;
        int x;
        cin >> c >> x;
        if (c == '|')
            for (int i = 0;i < 10;i++)// be one |
                if (x & (1 << i))bits[i] = 1;
        if (c == '&')
            for (int i = 0;i < 10;i++)// be zero &
                if (!(x & (1 << i)))bits[i] = 0;
        if (c == '^')
            for (int i = 0;i < 10;i++)// be revers ^
                if (x & (1 << i))bits[i] = (bits[i] >= 2 ? 5 - bits[i] : 1 - bits[i]);
    }
    cout << 3 << ed;
    int ans = 0;
    // bits = 2222222201
    // new we want create number have the same formate
    for (int i = 0;i < 10;i++)if (bits[i] == 3)ans ^= (1 << i);// ^ == +
    cout << "^ " << ans << ed;
    ans = 0;
    for (int i = 0;i < 10;i++)if (bits[i] == 1)ans ^= (1 << i);
    cout << "| " << ans << ed;
    ans = 0;
    for (int i = 0;i < 10;i++)if (bits[i] == 0)ans ^= (1 << i);
    cout << "& " << 1023 - ans << ed;
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++)
        // cout << "Case "<<i<<": ",
        doWork(i), cout << ed;
    Good_Bay 0;
}
