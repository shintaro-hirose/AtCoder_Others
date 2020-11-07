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
    int N;
    cin >> N;
    vector<ll> data(N);
    rep(i, N){
        cin >> data[i];
    }
    ll ans, prevDepthNode;
    ans = 0;
    for(int i = N; i >= 0; i--){
        if(1<<i < data[i]){
            cout << -1 << endl;
            return 0;
        }
        if(i == N){
            ans += data[i];
            prevDepthNode = data[i];
            continue;
        }
        if(data[i] + )
        if((prevDepthNode + 1) / 2)
    }
    
    return 0;
}
