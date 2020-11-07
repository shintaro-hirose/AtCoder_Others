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
    //愚直にやって間に合う？
    for(int i = 1; i <= n; i++){
        ll ans = 0;
        for(int x = 1; x <= 100; x++){
            if(x*x > i) break;
            for(int y = 1; y <= 100; y++){
                if(x*x + y*y > i) break;
                for(int z = 1; z <= 100; z++){
                    if(x*x + y*y + z*z + x*y + y*z + z*x > i) break;
                    if(x*x + y*y + z*z + x*y + y*z + z*x == i){
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}