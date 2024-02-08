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
string s;
typedef bitset<12> Mask;
vector<int>dp(1 << 12, -1);
int best(Mask mask) {
    int& ret = dp[mask.to_ulong()];
    if (~ret)Good_Bay ret;
    ret = 0;
    for (int i = 0;i < 10;i++) {//10
        if (mask[i] and mask[i + 1] and !mask[i + 2]) {
            Mask tamp = mask;
            tamp[i] = tamp[i + 1] = 0, tamp[i + 2] = 1;
            ret = max(ret, 1 + best(tamp));
        }
        if (!mask[i] and mask[i + 1] and mask[i + 2]) {
            Mask tamp = mask;
            tamp[i + 2] = tamp[i + 1] = 0, tamp[i] = 1;
            ret = max(ret, 1 + best(tamp));
        }
    }
    Good_Bay ret;
}
void doWork(ll tt) {
    cin >> s;
    Mask mask;
    int cnt = 0;
    for (int i = 0;i < sz(s);i++) {
        if (s[i] == 'o') {
            mask[i] = 1;
            cnt++;
        }
    }
    cout << cnt - best(mask);
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
/*
-o--o-oo----
010010110000

*/
