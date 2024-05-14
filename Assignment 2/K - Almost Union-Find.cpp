#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define EPS 1e-9
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define mem(arr, x) memset(arr,x,sizeof arr)
#define endl '\n'
#define PI acos(-1)
#define Ones(n) __builtin_popcount(n)
#define Onesl(n) __builtin_popcountll(n)
#define what_is(x) cerr << #x << " is " << x << endl;
#define precision(x) fixed << setprecision(x)
#define sz(x) (int)x.size()
#define pb push_back
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
#define print(x) for (int i = 0; i < sz(x); ++i) cout << x[i] << " \n"[i == sz(x) - 1]
#define print2(x) for (int i = 0; i < sz(x); ++i) {for (int j = 0; j < sz(x[i]); ++j) cout << x[i][j] << " \n"[j == sz(x[i]) - 1];}

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<bool> vb;
const ll MOD = 1e9 + 7;
const ll N = 2e5 + 5;
const int OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const int NINF = -1e9;
const int INF = 1e9;
int dx4[] = {0, 0, -1, 1};
int dy4[] = {-1, 1, 0, 0};
int dx8[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy8[] = {-1, 1, -1, 0, 1, -1, 0, 1};

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

struct DSU {
    vi par, size,sum;
    int n, comp;

    void init(int n) {
        this->n = n;
        comp = n;
        par.assign(n+n+1, -1);
        size.assign(n+n+1, 1);
        sum.assign(n+n+1, 0);
        int j = n+1;
        rep2(i, 1, n){
            // make them point to null node when change parent nothing changes
            par[i] = j;
            par[j] = j;
            sum[j] = i;
            j++;
        }
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u=find(u), v=find(v);
        if (u == v) return false;
        if (size[u] > size[v]) swap(u, v);
        comp--;
        par[u] = v;
        size[v] += size[u];
        sum[v] += sum[u];
        return true;
    }

    void move(int u, int v) {
        int uP = find(u), vP = find(v);
        if (uP == vP) return;
        sum[uP] -= u;
        sum[vP] += u;
        par[u] = vP;
        size[vP]++;
        size[uP]--;

    }

    int getSize(int u) {
        return size[find(u)];
    }

    int getComp() {
        return comp;
    }

    int getSum(int u) {
        return sum[find(u)];
    }
};

void solve() {
    int n, m;
    while(cin >> n >> m) {
        DSU dsu;
        dsu.init(n+1);
        rep(i, 0, m) {
            int c; cin >> c;
            if(c == 1){
                int u, v; cin >> u >> v;
                dsu.join(u, v);
            } else if (c == 2){
                int u, v; cin >> u >> v;
                dsu.move(u, v);
            }else{
                int u; cin >> u;
                cout<<dsu.getSize(u)<<" "<<dsu.getSum(u)<<endl;
            }
        }
    }
}


int main() {
    fast();
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}