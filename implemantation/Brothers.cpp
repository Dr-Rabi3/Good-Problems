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


void solve(ll tt){
    ll king,row,column,attacks;
    while( cin >> king >> row >> column >> attacks ){
        ll stop = min({king,row,column,attacks});
        if(!stop)break;
        vector<vector<ll>>leads(row,vector<ll>(column));
        vector<ll>attack(king,0);
        for(int i=0;i<king-1;i++)
            attack[i]=i+1;
        for(int i=0 ;i<row;i++)for(int j=0;j<column;j++)cin >> leads[i][j];
        while(attacks--){
            vector<vector<ll>>leadsTamp=leads;
            for(int i=0 ;i<row;i++){
                for(int j=0;j<column;j++){
                    if( j>0 && leads[i][j-1]==attack[leads[i][j]] ) leadsTamp[i][j-1]=leads[i][j];
                    if( j+1<column && leads[i][j+1]==attack[leads[i][j]] ) leadsTamp[i][j+1]=leads[i][j];
                    if( i>0 && leads[i-1][j]==attack[leads[i][j]] ) leadsTamp[i-1][j]=leads[i][j];
                    if( i+1<row && leads[i+1][j]==attack[leads[i][j]] ) leadsTamp[i+1][j]=leads[i][j];
                }
            }
            leads=leadsTamp;
        }
        for(int i=0 ;i<row;i++)for(int j=0;j<column;j++)cout << leads[i][j] << " \n"[j==column-1];
    }
}

int main(){
    Accept();
    int t=1;
    //cin >>t;
    for(int i=1;i<=t;i++)
        solve(i);//cout <<ed;
    Good_Bay;
}
