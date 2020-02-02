#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, K;
    cin >> N >> K;

    vector<ll > dp(N+1, -1);
    dp[0] = 1;

    for(ll i = 0; i < N; i++){
        if(dp[i] == -1) continue;
        dp[i+1] = min(2 * dp[i], dp[i]+K);
    }

    cout << dp[N] << endl;

}