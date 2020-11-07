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

int main() {
    int N; cin >>N;
    vector<double> P(N);
    rep(i, N) cin >> P[i];
    // dp[i][j] i枚投げた時にj個表が出る確率
    vector<vector<double>> dp(N+1, vector<double>(N+1));
    dp[0][0] = 1;
    rep(i,N){
        dp[i+1][0] = dp[i][0] * (1 - P[i]);
    }
    rep(i, N){
        for(int j = 1; j <= N; j++){
            dp[i+1][j] = dp[i][j-1] * P[i] + dp[i][j] * (1 - P[i]);
        }
    }
    double ans = 0;
    for(int i = (N+1)/2; i <= N; i++){
        ans += dp[N][i];
    }
    cout << fixed << setprecision(15) <<  ans << endl;
    return 0;
}