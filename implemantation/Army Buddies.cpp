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
    ll n,m,st,en,x,y;
    while(cin >>n>>m){
        if(n==0)break;
        vector<ll>v1(n+2,0),v2(n+2,0);
        /*
               1 2 3 4 5 6 7 8 9 10
   left (v1) = -1 1 2 3 4 5 6 7 8 9 10
   right(v2) = 2 3 4 5 6 7 8 9 10 -1 
             l = 2     r = 5
   left (v1) = -1 1 2 3 4 1 6 7 8 9
   right(v2) = 6 3 4 5 6 7 8 9 10 -1
             l = 6     r = 9 
   left (v1) = -1 1 2 3 4 1 6 7 8 1
   right(v2) = 10 3 4 5 6 7 8 9 10 -1
             l = 1      r = 1
   left (v1) = -1 1 2 3 4 1 6 7 8 -1
   right(v2) = 10 3 4 5 6 7 8 9 10 -1
             l = 10     r = 10
   left (v1) =  -1 1 2 3 4 1 6 7 8 -1
   right(v2) = 10 3 4 5 6 7 8 9 10 -1
          */
        for(int i=1;i<=n;i++)
            v1[i]+=i-1,v2[i]+=i+1;
        v1[1]=-1,v2[n]=-1;
        while(m--){
            cin >>x>>y;
			if (v1[x] != -1){
				cout <<v1[x];
				v2[v1[x]]=v2[y];
			}
			else cout<<'*';
			if (v2[y]!= -1){
				cout <<' '<< v2[y]<<ed;
                v1[v2[y]]=v1[x];
			}
			else
				cout <<" *\n";
        }
        cout << '-'<<ed;
    }
}

int main(){
    MoHaMeD_AbdalRaZeK
    //freopen("smallest.in","r",stdin);
    int t=1;
    //cin >>t;
    for(int i=1;i<=t;i++)
        solve(i);//cout << ed;
    Good_Bay;
}
