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
    int N; cin >> N;
    vector<vector<int>> Hs(N + 1, vector<int>(3));
    rep(i, N) cin >> Hs[i + 1][0] >> Hs[i + 1][1] >> Hs[i + 1][2];

    // dp[i][0]: i 番目に A を選んだ場合の最大値
    // dp[i + 1][0] = max(dp[i][1] + bi, dp[i][2] + ci)
    vector<vector<int>> dp(N + 1, vector<int>(3));
    dp[1] = Hs[1];
    for(int i = 1; i < N; i++){
        rep(j, 3){
            dp[i + 1][j] = max(dp[i][(j+1)%3] + Hs[i+1][j], dp[i][(j+2)%3] + Hs[i+1][j]);
        }
    }
    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << endl;
    return 0;
}