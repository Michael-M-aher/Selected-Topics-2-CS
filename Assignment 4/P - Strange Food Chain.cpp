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


class DSU {
public:
    vector<int> parent, type;

    DSU(int n) {
        parent.resize(n + 1);
        type.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] == u) return u;
        int tmp = parent[u];
        parent[u] = find(parent[u]);
        type[u] = (type[u] + type[tmp]) % 3;
        return parent[u];
    }

    void join(int u, int v, int t) {
        int rootU = find(u);
        int rootV = find(v);
        parent[rootU] = rootV;
        type[rootU] = (type[v] - type[u] + t + 3) % 3;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    DSU dsu(n);
    int falseCount = 0;

    for (int i = 0; i < k; ++i) {
        int t, x, y;
        cin >> t >> x >> y;
        if (x > n || y > n) {
            falseCount++;
            continue;
        }
        int rootX = dsu.find(x);
        int rootY = dsu.find(y);
        t--;
        if (rootX == rootY) {
            int relation = (dsu.type[x] - dsu.type[y] + 3) % 3;
            if (relation != t) falseCount++;
        } else {
            dsu.join(x, y, t);
        }
    }
    cout << falseCount << endl;
}


int main() {
    fast();
//    freopen("input.txt","rt",stdin);
//    freopen("output.txt","wt",stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}