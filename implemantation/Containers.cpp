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
    string s;// ACMICPC
    int idx = 0;
    while (getline(cin, s) && ++idx ) {
        if (s == "end") break;
        vector<stack<char>>v;
        for(int i=0;i<sz(s);i++) {
            bool b=0;
            for(int j=0;j<sz(v);j++) {
                if (v[j].top() >= s[i]) {
                    b=1;
                    v[j].push(s[i]);
                    break;
                }
            }
        /**
          A
        1- A
          CCCCBBBBAAAA
        1- C C C C B B B B A A A A
          CBACBACBACBA
        1-  C B A A A A
        2-  C B B B
        3-  C C
           ACMICPC
        1-  A
        2-  C C C
        3-  M I
        4-  P
        **/
            if (!b) {
                stack<char>sk;
                sk.push(s[i]);
                v.push_back(sk);
            }
        }
        cout <<"Case "<<idx<<": " <<sz(v)<<ed;
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
