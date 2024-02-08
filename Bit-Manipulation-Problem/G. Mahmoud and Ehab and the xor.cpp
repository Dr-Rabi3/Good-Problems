//  https://codeforces.com/group/u3Ii79X3NY/contest/274952/problem/G


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
    int n, m;
    cin >> n >> m;// n = 5 , m = 5;
    // to take m by n element
    // you need repeat all number except m ( 2 ^ 2 = 0 ^ 5 = 5)
    // we will choose 2 big number like 1 << 17 , 1 << 18
    // new we want to repeated it, we will repeated it in only one number ((1<<17) ^ (1<<18)),i.e (1 ^ 2 ^ (1 ^ 2) = (1 ^ 2 ^ 3) = 0)
    // new we have 3 number ( 1<<17 , 1<<18 , (1<<17) ^ (1<<18) ,)
    // new we need add numbers from 1 to n - 2 and duplicated it in only on number let be ((1<<17) ^ (1<<18))
    // new we have ((1<<17) ^ (1<<18) ^ 1 ^ 2) ^ (1<<17) ^ (1<<18) ^ 1 ^ 2 = 0
    // finally we add m to this element to became ((1<<17) ^ (1<<18) ^ 1 ^ 2 ^ 5)
    // ((1<<17) ^ (1<<18) ^ 1 ^ 2 ^ 5) ^ (1<<17) ^ (1<<18) ^ 1 ^ 2 = 0 ^ 5 = 5
    // n = ((1<<17) ^ (1<<18) ^ 1 ^ 2 ^ 5) ^ (1<<17) ^ (1<<18) ^ 1 ^ 2
    //  :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) :) 
    if (n == 1)cout << "YES\n" << m;
    else if (n == 2 && !m)cout << "NO";
    else if (n == 2)cout << "YES\n" << 0 << ' ' << m;
    else {
        int x = 1LL << 17, z = 1LL << 18;
        cout << "YES\n" << x << ' ' << z << ' ';
        int y = x ^ z;
        for (int i = 1;i < n - 2;i++)
            cout << i << ' ', y ^= i;
        cout << (y ^ m);
    }
}
int main() {
    Accept();
    int t = 1;
    // cin >> t;
    for (int i = 1;i <= t;i++)
        // cout << "Case "<<i<<": ",
        doWork(i),cout << ed;
    Good_Bay 0;
}
