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
const ll N = 25;
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


int n, k, arr[N];
ll s, fact[19];
vector<ll> subsets[2][26];

void mim(int st, int e, ll sum, int i, int idx) {
    if(st == e) {
        subsets[idx][i].push_back(sum);
        return;
    }

    mim(st + 1, e, sum, i, idx);
    if(sum + arr[st] <= s)
        mim(st + 1, e, sum + arr[st], i, idx);
    if(arr[st] <= 18 && sum + fact[arr[st]] <= s && i < k)
        mim(st + 1, e, sum + fact[arr[st]], i + 1, idx);
}

void solve() {
    fact[0] = 1;
    rep(i, 1, 19)
        fact[i] = fact[i - 1] * i;

    cin >> n >> k >> s;
    read(arr, n);

    mim(0, n / 2, 0, 0, 0);
    mim(n / 2, n, 0, 0, 1);

    rep(i, 0, 26)
        sort(all(subsets[0][i]));

    ll ans = 0;
    rep(i, 0, k + 1) {
        for(auto val : subsets[1][i]) {
            rep(q, 0, k + 1 - i) {
                auto bounds = equal_range(subsets[0][q].begin(), subsets[0][q].end(), s - val);
                ans += bounds.se - bounds.fi;
            }
        }
    }
    cout << ans << endl;
}



int main() {
    fast();
//    freopen("input.txt","rt",stdin);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}