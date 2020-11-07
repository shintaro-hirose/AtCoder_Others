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
    vector<int> As(n);
    rep(i,n) cin >> As.at(i);
    ll money = 1000;
    ll kabu = 0;
    // 次の日をみて、株価が下がっていれば全力で売る
    // 株価が上がっていれば全力で買う
    rep(i,n-1){
        if(As.at(i) > As.at(i+1)){
            money += As.at(i) * kabu;
            kabu = 0;
        } else {
            ll buy = money / As.at(i);
            money -= buy * As.at(i);
            kabu += buy;
        }
    }
    money += As.at(n-1) * kabu;
    cout << money << endl;
    return 0;
}