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
    int x; cin >> x;
    int ans;
    if(x>=1800){
        ans = 1;
    } else if(x>= 1600){
        ans = 2;
    } else if(x>= 1400){
        ans = 3;
    } else if(x>= 1200){
        ans = 4;
    } else if(x>= 1000){
        ans = 5;
    } else if(x>= 800){
        ans = 6;
    } else if(x>= 600){
        ans = 7;
    } else if(x>= 400){
        ans = 8;
    }
    cout << ans << endl;
    return 0;
}