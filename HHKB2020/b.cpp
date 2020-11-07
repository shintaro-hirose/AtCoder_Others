#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int H, W; cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin >> S[i];
    vector<vector<bool>> memo(H, vector<bool>(W, false)); 
    int hmove[4] = {1,0,-1,0};
    int wmove[4] = {0,1,0,-1};
    int ans = 0;
    rep(hi,H){
        rep(wi, W){
            memo[hi][wi] = true;
            if(S[hi][wi] == '#') continue;
            rep(j,4){
                int nh,nw;
                nh = hi + hmove[j];
                nw = wi + wmove[j];
                if(0<=nh && 0<=nw && nh<H && nw<W && S[nh][nw] != '#' && !memo[nh][nw]){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}