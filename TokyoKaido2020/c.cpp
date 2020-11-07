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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(ki, k){
        vector<int> b(n + 1);
        rep(i, n){
            int l = max(0, i - a[i]);
            int r = min(i + a[i] + 1, n);
            b[l]++;
            b[r]--;
        }
        rep(i,n) b[i + 1] += b[i];
        b.pop_back();
        if(a == b) break;
        a = b;
    }
    rep(i,n) cout << a[i] << endl;
    return 0;
}
