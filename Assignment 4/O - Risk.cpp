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

struct Node {
    int id=-1;
    bool vis=false;
    vector<Node*> adj={};
    Node(int _id) : id(_id) {}
};

vector<Node*> nodes(20);

vector<vector<pii>> adj(N);
int dist[N], parent[N];
bool vis[N];


void dijkstra(int x){
    rep(j, 0, 20) {
        dist[j] = LOO;
        vis[j] = false;
        parent[j] = -1;
    }
    dist[x] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, x});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int u = cur.second;
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto v : nodes[u]->adj) {
            if (dist[u] + 1 < dist[v->id]) {
                dist[v->id] = dist[u] + 1;
                parent[v->id] = u;
                pq.push({dist[v->id], v->id});
            }
        }
    }
}

void solve() {
    int n,c=1;
    while (cin>>n){
        nodes.clear();
        nodes.resize(20);
        rep(i, 0, 20) {
            nodes[i] = new Node(i);
        }
        rep(i, 0, n) {
            int x;cin>>x;
            x--;
            nodes[0]->adj.push_back(nodes[x]);
            nodes[x]->adj.push_back(nodes[0]);
        }
        rep(i, 1, 19) {
            cin >> n;
            rep(j, 0, n) {
                int x;
                cin >> x;
                x--;
                nodes[i]->adj.push_back(nodes[x]);
                nodes[x]->adj.push_back(nodes[i]);
            }
        }
        printf("Test Set #%d\n",c);
        int q;
        cin >> q;
        rep(i, 0, q) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            dijkstra(x);
//            cout << x + 1 << " to " << y + 1 << ": "<<dist[y]<<endl;
            printf("%2d to %2d: %d\n", x + 1, y + 1, dist[y]);

        }
        c++;
        printf("\n");
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