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

const int ALPHA = 128;

struct Trie {
    vector<map<char, int>> trie;
    vector<int> id, f, len;

    Trie() {
        addNode();
    }

    int addNode() {
        trie.emplace_back();
        id.push_back(-1);
        f.push_back(0);
        return (int) trie.size() - 1;
    }

    int getNxt(int u, char c) {
        int w = u;
        while (!trie[w].count(c))
            w = f[w];
        w = trie[w][c];
        return w;
    }

    void calcF() {
        queue<int> q;
        for (int c = 0; c < ALPHA; ++c) {
            int v = trie[0].emplace(c, 0).first->second;
            if (v) q.push(v), f[v] = 0;
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &[c, v]: trie[u]) {
                q.push(v);
                int w = getNxt(f[u], c);
                f[v] = w;
            }
        }
    }

    int insert(string str, int idx) {
        int cur = 0;
        len.push_back(0);
        for (int i = 0; str[i]; ++i) {
            int nxt = trie[cur].emplace(str[i], -1).first->second;
            if (nxt == -1) nxt = addNode();
            cur = trie[cur][str[i]] = nxt;
            len.back()++;
        }
        if (!~id[cur])
            id[cur] = idx;
        return id[cur];
    }

    vector<vector<int>> match(string str) {
        vector<vector<int>> ret(len.size());
        int cur = 0;
        for (int i = 0; str[i]; ++i) {
            cur = getNxt(cur, str[i]);
            for (int u = cur; u; u = f[u]) {
                if (id[u] != -1)
                    ret[id[u]].push_back(i - len[u] + 1);
            }
        }
        return ret;
    }
};

string str, pat;

void solve() {
    Trie trie;
    int n;
    cin >> str;

    cin >> n;
    vector<int> idx(n);
    for (int i = 0; i < n; ++i) {
        cin >> pat;
        idx[i] = trie.insert(pat, i);
    }
    trie.calcF();
    auto res = trie.match(str);
    for (int i = 0; i < n; ++i) {
        cout << (!res[idx[i]].empty() ? "y" : "n") << endl;
    }
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