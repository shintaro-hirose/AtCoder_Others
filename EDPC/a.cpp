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
    vector<int> Hs(N + 1);
    rep(i, N) cin >> Hs[i + 1];
    vector<int> dp(N+1, INF);
    dp[1] = 0;
    for(int i = 1; i <= N; i++){
        if(i + 1 <= N){
            dp[i + 1] = min(dp[i + 1], dp[i] + abs(Hs[i] - Hs[i + 1]));
        }
        if(i + 2 <= N){
            dp[i + 2] = min(dp[i + 2], dp[i] + abs(Hs[i] - Hs[i + 2]));
        }
    }
    cout << dp[N] << endl;
    return 0;
}