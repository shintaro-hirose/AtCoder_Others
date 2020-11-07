#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e11)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N, W; cin >> N >> W;
    vector<int> ws(N + 1);
    vector<int> vs(N + 1);
    rep(i, N) cin >> ws[i + 1] >> vs[i + 1];

    // dp[i][j]: i 番目までのアイテムから価値が j 以上になるように選んだ時の最小重さ
    // dp[i + 1][j] = min(dp[i][j], dp[i][j - vs[i + 1]] + ws[i + 1])
    vector<vector<ll>> dp(N + 1, vector<ll>(100010, INF));
    dp[0][0] = 0;
    rep(i, N) rep(j, 100010){
        if(j - vs[i + 1] >= 0) dp[i + 1][j] = min(dp[i][j], dp[i][j - vs[i + 1]] + ws[i + 1]);
        else dp[i + 1][j] = dp[i][j];
    }
    for(int i = 100000; i >= 0; i--){
        if(dp[N][i] <= W) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}