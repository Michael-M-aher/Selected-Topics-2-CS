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

int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};

struct Node {
    int dis = -1;
};

struct Cell {
    int r, c;
    Cell(int r, int c) : r(r), c(c) {}
};

string src, tar;


int bfs(int sr, int sc, int tr, int tc, int n, int m) {
    vector<vector<Node>> nodes(n, vector<Node>(m));
    queue<Cell> q;
    q.emplace(sr, sc);
    nodes[sr][sc].dis = 0;
    while(!q.empty()) {
        Cell cur = q.front();
        q.pop();
        if (cur.r == tr && cur.c == tc) {
            return nodes[tr][tc].dis;
        }
        for (int i = 0; i < 8; ++i) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && nodes[nr][nc].dis == -1) {
                nodes[nr][nc].dis = nodes[cur.r][cur.c].dis + 1;
                q.emplace(nr, nc);
            }
        }
    }
    return nodes[tr][tc].dis;
}


void solve() {
    while (cin>>src>>tar){
        if (src==tar){
            cout<<"To get from "<<src<<" to "<<tar<<" takes 0 knight moves.\n";
            continue;
        }
        int sr = src[0]-'a', sc = src[1]-'1';
        int tr = tar[0]-'a', tc = tar[1]-'1';
        int dis = bfs(sr, sc, tr, tc, 8, 8);
        cout<<"To get from "<<src<<" to "<<tar<<" takes "<<dis<<" knight moves.\n";
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