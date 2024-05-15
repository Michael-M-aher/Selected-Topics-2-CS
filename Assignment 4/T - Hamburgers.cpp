#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define EPS 1e-9
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define mem(arr, x) memset(arr,x.sizeof arr)
#define endl '\n'
#define PI acos(-1)
#define Ones(n) __builtin_popcount(n)
#define Onesl(n) __builtin_popcountll(n)
#define what_is(x) cerr << #x << " is " << x << endl;
#define precision(x) fixed << setprecision(x)
#define sz(x) (int)x.size()
//#define pb push_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define rep2(i, a, b) for (int i = a; i <= b; ++i)
#define repr(i, a, b) for (int i = a; i > b; --i)
#define repr2(i, a, b) for (int i = a; i >= b; --i)
#define repit(it, x) for (auto it = x.begin(); it != x.end(); ++it)
#define reprit(it, x) for (auto it = x.rbegin(); it != x.rend(); ++it)
#define read(x, n) for (int i = 0; i < n; ++i) cin >> x[i]
#define read2(x, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> x[i][j]
#define print(x) for (int i = 0; i < sz(x); ++i) cout << x[i] << " \n"[i == sz(v) - 1]
#define print2(x) for (int i = 0; i < sz(x); ++i) {for (int j = 0; j < sz(x[i]); ++j) cout << x[i][j] << " \n"[j == sz(x[i]) - 1];}

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
const ll MOD = 1e9 + 7;
const ll N = 2e5 + 5;
const int OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool valid(vl &rec,vl &n,vl &p, ll r,ll mid){
    vl need(3);
    rep(i,0,3){
        need[i]=max(0ll,rec[i]*mid-n[i]);
    }
    ll cost=0;
    rep(i,0,3){
        cost += need[i]*p[i];
    }
    return (cost<=r);
}

void solve() {
    string s;cin>>s;
    vl rec(3);
    rep(i,0,sz(s)){
        if(s[i]=='B')rec[0]++;
        else if(s[i]=='S')rec[1]++;
        else rec[2]++;
    };
    vl n(3);read(n,3);
    vl p(3);read(p,3);
    ll r;cin>>r;
    ll st=0,en=1e15+5;
    while(st<en){
        ll mid=(st+en)/2;
        if(valid(rec,n,p,r, mid))st=mid+1;
        else en=mid;
    }
    cout<<st-1<<endl;
}


int main() {
    fast();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}