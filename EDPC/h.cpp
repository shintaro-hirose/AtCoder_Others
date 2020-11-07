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

int H,W;
vs S;
int hmove[2] = {1,0};
int wmove[2] = {0,1};
vvl dp;
vvb seen;

ll f(int h, int w){
    if(seen[h][w]) return dp[h][w];
    seen[h][w] = true;
    rep(i, 2){
        int nh, nw;
        nh = h - hmove[i];
        nw = w - wmove[i];
        if(nh>=0 && nw>=0 && nh<H && nw<W && S[nh][nw] == '.'){
            dp[h][w] = (f(nh, nw) + dp[h][w]) % mod;
        }
    }
    return dp[h][w];
}

int main() {
    cin >> H >> W;
    S = vs(H);
    rep(i, H) cin >> S[i];

    dp = vvl(H, vl(W));
    dp[0][0] = 1;
    seen = vvb(H, vb(W, false));
    seen[0][0] = true;

    cout << f(H-1, W-1) << endl;
}