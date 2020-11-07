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
// #define debug(a) cout << "["; rep(i,a.size()) cout << a[i] << ", "; cout<<"]"<< endl;

const ll mod = 1000000007;

int main() {
    int n; cin >> n;
    vector<ll> As(10010);

    rep(x, 100) rep(y, 100) rep(z,100){
        int xx=x+1, yy=y+1, zz=z+1;
        ll a;
        a = xx*xx + yy*yy + zz*zz + xx*yy + yy*zz + zz*xx;
        if(a>10000) break;
        As.at(a)++;
    }
    rep(i,n){
        cout << As.at(i+1) << endl;
    }
    return 0;
}