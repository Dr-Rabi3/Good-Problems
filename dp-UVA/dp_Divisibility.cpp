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

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x: v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}
void Accept(){
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
int dx[] = { -1 ,  0 ,  1 , 1 , 1 , 0 , -1 , -1 };
int dy[] = { -1 , -1 , -1 , 0 , 1 , 1 ,  1 ,  0 };
int n, k;
vector<int>v;
vector<vector<int>>dp;
int fix(int x) {
    Good_Bay(x % k + k) % k;
}
bool canDiv(int i, int Mod) {
    int& ret = dp[i][Mod];
    if (~ret)Good_Bay ret;
    if (i == n)Good_Bay ret = (Mod == 0);
    Good_Bay ret = canDiv(i + 1, fix(Mod + v[i])) || canDiv(i + 1, fix(Mod - v[i]));
}
void doWork(int tt) {
    cin >> n >> k;
    v = vector<int>(n);
    dp.assign(n + 10, vector<int>(k + 10, -1));
    cin >> v;
    cout << (canDiv(0, 0) ? "Divisible" : "Not divisible");
}
int main() {
    Accept();
    int t=1;
    cin >>t;
    for (int i = 1;i <= t;i++)
        // cout << "Case "<<i<<":\n",
        doWork(i),cout << ed;
    Good_Bay 0;
}


