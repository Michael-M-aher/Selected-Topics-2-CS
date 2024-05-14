#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
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

void solve() {
    int n;cin >> n;

    if (n % 2 != 0) {
        int a = 2;
        while (true) {
            int b = n-1-a;
            if (gcd(a, b) == 1) {
                cout << a << " " << b << " " << 1;
                break;
            }
            a++;
        }
    }
    else {
        cout << n/2 << " " << (n/2)-1 << " " << 1;
    }
}

int main() {
    fast();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
    return 0;
}