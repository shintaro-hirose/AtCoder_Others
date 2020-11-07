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
    ll N, K; cin >> N >> K;
    vector<ll> Hs(N+1);
    rep(i, N) cin >> Hs[i+1];
    vector<ll> dp(N + 1, INF);
    dp[1] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(i + j <= N){
                dp[i + j] = min(dp[i + j], dp[i] + abs(Hs[i] - Hs[i + j]));
            }
        }
    }
    cout << dp[N] << endl;
    return 0;
}