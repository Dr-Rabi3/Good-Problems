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
#define     numOfDigits(x)           ((ll)log10(x) + 1)
#define     Good_Bay                 return 0
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

ll count(ll l,ll r,ll a){
    return ((r-l+2) / (a+1));
}

void solve(ll tt){
    ll n,m,i=0;
    while(cin >>n>>m && ++i ){
        if(n==0 && m==0 )break;
        cout << "Case "<<i <<':'<<ed;
        deque<ll>dq(min(n,1000LL));
        iota(all(dq),1);
        while(m--){
            char c;
            cin >>c;
            if(c=='N'){
                cout << dq.front()<<ed;
                dq.push_back(dq.front());
                dq.pop_front();
            }else {
                cin >>n;
                for(int i=0 ;i<sz(dq);i++){
                    if(dq[i]==n)
                        dq.erase(dq.begin()+i);
                }
                dq.push_front(n);
            }
        }
    }
}

int main(){
    Accept();
    int t=1;
   // cin >>t;
    for(int i=1;i<=t;i++)
        solve(i);//cout <<ed;
    Good_Bay;
}
