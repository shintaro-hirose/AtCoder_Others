#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e16)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    int N, M, T, K;
    cin >> N >> M >> T >> K;
    // 1-indexed
    vector<vector<l_l>> paths(N+1, vector<l_l>(0));
    vector<ll> Cs(N + 1);
    vector<ll> Ds(N + 1);
    vector<ll> ans(N + 1, INF);     // ans[i]: iまで進んだときの最小時間

    for(int i = 1; i <= M; i++){
        ll A,B,C,D; cin >> A >> B >> C >> D;
        paths[A].push_back(make_pair(B, i));
        paths[B].push_back(make_pair(A, i));
        Cs[i] = C;
        Ds[i] = D;
    }
    ans[1] = 0;

    queue<ll> q;
    q.push(1);
    while(!q.empty()){
        ll cn = q.front();
        q.pop(); 
        for(l_l p: paths[cn]){
            ll nn = p.first;
            ll d = p.second;
            ll timeAfterMove;
            ll now = ans[cn];
            if(Ds[d] - abs(T - now) > K){
                if(T>now){
                    timeAfterMove = T + K - Ds[d];
                } else {
                    timeAfterMove = T - K + Ds[d];
                }
            } else {
                timeAfterMove = now;
            }
            timeAfterMove += Cs[d];
            if(timeAfterMove > ans[nn]) continue;
            q.push(nn);
            ans[nn] = timeAfterMove;
        }
    }

    if(ans[N] == INF) {
        cout << -1 << endl;
    } else {
        cout << ans[N] << endl;
    }

    return 0;
}