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
ll target;
string s;
vector<string>ans;
void creat(string cur_sol , int idx , int cur_val , int last_val){
    if ( idx == sz(s)){
        if ( cur_val == target ) ans.push_back(cur_sol);
        Good_Bay;
    }
    for ( int i = idx ; i < sz(s) ; i++ ){
        if (i != idx && s[idx] == '0') break;// ignoring case which start with 0 as they are useless for evaluation
        string part = s.substr( idx , i + 1 - idx );
        int cur = atoi(part.c_str());
        if ( !idx ) creat(cur_sol + part , i + 1 , cur ,cur );
        else {
            creat(cur_sol + "+" + part , i + 1 , cur_val + cur , cur );
            creat(cur_sol + "-" + part , i + 1 , cur_val - cur , -cur );
            creat(cur_sol + "*" + part , i + 1 , cur_val * cur , last_val * cur );
        }
    }
}
void doWork(ll tt){
    cin >> s >> target ;
    creat( "" , 0 , 0 , 0 );
    for( auto i : ans) cout << i << ed;
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
