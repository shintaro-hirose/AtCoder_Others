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
    ll A,B,C,D; cin >> A >> B >> C >> D;
    string ans;
    if((A<=D && B>=C) || (C<=B && D>=A)){
        ans = "Yes";
    } else {
        ans = "No";
    }
    cout << ans << endl;
    return 0;
}