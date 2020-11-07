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
    int N, W; cin >> N >> W;
    vector<int> ws(N + 1);
    vector<int> vs(N + 1);
    rep(i, N) cin >> ws[i + 1] >> vs[i + 1];

    // dp[i][j]: i 番目までのアイテムから重さがj以下になるよう選んだときの価値の最大値
    // dp[i + 1][j] = max(dp[i][j], dp[i][j - ws[i + 1] + vs[i + 1])
    vector<vector<ll>> dp(N + 1, vector<ll>(W + 1));
    rep(i, N){
        for(int j = 1; j <= W; j++){
            if(j - ws[i + 1] >= 0){
                dp[i + 1][j] = max(dp[i][j], dp[i][j - ws[i + 1]] + vs[i + 1]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
    cout << dp[N][W] << endl;
    return 0;
}