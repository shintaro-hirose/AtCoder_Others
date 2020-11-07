#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

int main() {
    string S, T;
    cin >> S >> T;
    int NS = S.size();
    int NT = T.size();
    // dp[i][j] = Sをi, Tをjまで見た時のMAX長
    vvi dp(NS+1, vi(NT+1));
    rep(i, NS)rep(j, NT){
        if(S[i] == T[j]){
            dp[i+1][j+1] = dp[i][j]+1;
        } else {
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    int len = dp[NS][NT];
    string ans = "";
    int i = NS;
    int j = NT;
    while(len>0){
        if(S[i-1]==T[j-1]){
            ans = T[j-1] + ans;
            i--;
            j--;
            len--;
        } else if(dp[i][j] == dp[i-1][j]){
            i--;
        } else {
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}