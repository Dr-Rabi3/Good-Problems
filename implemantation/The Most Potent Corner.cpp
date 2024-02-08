/**
 *                بسم الله الرحمن الرحيم
 *   Name   :  Mohamed Abdelrazek Abdo :D
 *   Handle :  Dr.rabi3
 *   From   :  Qena
 *   Never Give Up  :D
**/
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
#define     mod                      1'000'000'007
#define     OO                       2'000'000'000
#define     EPS                      1e-7
#define     pi                       acos(-1)
#define     p2(x)                    (x&(x-1))
#define     numofdigits(x)           ((ll)log10(x) + 1)
#define     Good_Bay                 return 0
#define     MoHaMeD_AbdalRaZeK       ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

template < typename T = int > istream& operator >> (istream &in, vector < T > &v) {
    for (auto &x: v) in >> x;
    return in;
}

template < typename T = int > ostream& operator << (ostream &out, const vector < T > &v) {
    for (const T &x: v) out << x << ' ';
    return out;
}

void solve(ll tt){
    ll n;
    while(cin >>n){
        vector<ll>weights(1<<n),Potency(1<<n);
        cin >>weights;
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                Potency[i]+=weights[i^(1<<j)];
            }
        }
        ll ans=0;
        /**
     2   j= 0 1     1 2
    i=  0 1 2 3   (i^(1<<j))
    1-  1 0 3 2
    2-  2 3 0 1
        1 1 1 1
   sum =2 2 2 2    ans =4
   ------------------------------
           1 2 4
    3   j= 0 1 2     (i^(1<<j))
    i=  0 1 2 3 4 5 6 7
    1-  1 0 3 2 5 6 7 6
    2-  2 3 0 1 6 7 4 5
    3-  4 5 6 7 0 1 2 3
        82 73 8 49 120 44 242 58
   sum=201 175 373 139 368 251 186 335 
    ans = 368 + 215 = 619
        **/
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                ans=max(ans,Potency[i]+Potency[i^(1<<j)]);
            }
        }
        printf("%ld\n",ans);
    }
}

int main(){
    MoHaMeD_AbdalRaZeK
    //freopen("smallest.in","r",stdin);
    int t=1;
    //cin >>t;
    for(int i=1;i<=t;i++)
        solve(i);//cout <<ed;
    Good_Bay;
}
