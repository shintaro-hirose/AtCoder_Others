#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
int N, M;
vvi adj;

int dp[100010];
ll f(int x){
    if(dp[x] != -1) return dp[x];
    ll r = 0;
    for(int y: adj[x]){
        r = max(r, f(y)+1);
    }
    return dp[x] = r;
}

int main() {
    cin >> N >> M;
    adj = vvi(N, vi(0));
    rep(i, M){
        int x,y; cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
    }

    rep(i, N) dp[i] = -1;

    ll ans = 0;
    rep(i, N) ans = max(ans, f(i));
    cout << ans << endl;
    return 0;
}