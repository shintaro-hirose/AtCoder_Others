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
    vector<vector<int>> places(n, vector<int>(3));
    rep(i,n){
        int x,y,p; cin >> x >> y >> p;
        places.at(i) = {x,y,p};
    }
    //路線の選択肢は高々40000個
    //40000個から1本だけ選んだ時のSが小さい順に選べば良い？
    for(int i = -10000; i <= 10000; i++){
        ll s = 0;
        rep(ni,n){
            int x,y,p;
            x = places.at(ni).at(0);
            y = places.at(ni).at(1);
            p = places.at(ni).at(2);
            s += min(min(abs(x), abs(y)), abs(y - i)) * (ll)p;
        }
        
    }
    return 0;
}