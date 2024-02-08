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
int dx[] = { 0 , 1 , 1 , 0 , 0 , 0 , -1 , -1 };
int dy[] = { 0 , 1 , 0 , 1 , 0 , -1 , 0 , -1 };
//__builtin_popcount(n); count num of one in binary 
//__builtin_clz(n); count num of bits before the last one ex: 10 has 28 (32 - 4) before it. ( 32 - num of bits for the digit ) 
//__builtin_ctz(n); Number of trailing zeroes
//__lg(n); num of bit of last one in binary representation
// (i & -i) value of last one of bits
// if (n % 4 == 0) = n;if (n % 4 == 1) = 1;if (n % 4 == 2) = n + 1;else = 0 ; ( Direct XOR of all numbers from 1 to n )
//  XOR of all subsets of a set  is always 0
// the most significant set bit (MSB):n |= n >> 1;n |= n >> 2;n |= n >> 4;n |= n >> 8;n |= n >> 16;n = n + 1;return (n >> 1);
// S | S + 1; turn On First Zero form right to left
// S & S - 1; turn off first one from right to left 
// S | S - 1; turn on all zeros from left util first one
// S & S + 1; turn off all ones from left util first zero
void print(int dif , vector<int>v , int s , int e){
    if ( abs(dif) > ( e - s + 1 ) / 2 ) Good_Bay;// We can't cover difference of more than n with 2n bits
    if ( s > e ) {
        if ( !dif ){
            for(auto i:v)cout << i;
            cout << ed;
        }
        Good_Bay;
    }
    v[s]=1,v[e]=1;
    print( dif , v , s+1 , e-1 );
    v[s]=0,v[e]=0;
    print( dif , v , s+1 , e-1 );
    v[s]=1,v[e]=0;
    print( dif-1 , v , s+1 , e-1 );
    v[s]=0,v[e]=1;
    print( dif+1 , v , s+1 , e-1 );
    Good_Bay;
}
void doWork(ll tt){
    ll n;
    cin >> n;
    vector<int>v(n*2);
    print( 0 , v , 0 , n*2 -1);
}

int main(){
    Accept();
    int t=1;
    // cin >>t;
    for(int i=1;i<=t;i++)
        // cout << "Case "<<i<<":\n",
        doWork(i),cout <<ed;
    Good_Bay 0;
}
