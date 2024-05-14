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
const ll N = 1e7 + 100;
const int OO = 0x3f3f3f3f;
const ll LOO = 0x3f3f3f3f3f3f3f3f;
const int NINF = -1e9;
const int INF = 1e9;
int dx4[] = {0, 0, -1, 1};
int dy4[] = {-1, 1, 0, 0};
int dx8[] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy8[] = {-1, 1, -1, 0, 1, -1, 0, 1};

ll sum[N];
int divis[N];
int ans[N];

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void sieve() {
    fill(divis, divis + N, -1);
    divis[1] = 1;
    for (int i = 2; i * i < N; ++i) {
        if (divis[i] == -1) {
            divis[i] = i;
            for (int j = i * i; j < N; j += i) {
                if (divis[j] == -1) {
                    divis[j] = i;
                }
            }
        }
    }
}

void calc() {
    sieve();
    sum[1] = 1;
    rep(i, 2, N) {
        if (divis[i] == -1) {
            divis[i] = i;
            sum[i] = i + 1;
        } else {
            int j = i;
            sum[i] = 1;
            while (j % divis[i] == 0) {
                j /= divis[i];
                sum[i] = sum[i] * divis[i] + 1;
            }
            sum[i] *= sum[j];
        }
    }

    fill(ans, ans + N, -1);
    repr(i, N - 1, 0) {
        if (sum[i] < N) {
            ans[sum[i]] = i;
        }
    }
}

void solve() {
    int c;
    cin >> c;
    cout << ans[c] << endl;
}

int main() {
    fast();
    calc();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
