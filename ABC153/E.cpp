#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll H, N;

int main() {

    
    cin >> H >> N;
    ll ng = -1; ll ok = INF;

    vector<pi > AB;
    for(ll i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        AB.push_back(make_pair(a, b));
    }
    
    vector<ll > dp(19191919, INF);
    dp[0] = 0;

    for(ll i = 0; i <= H; i++){
        for(ll j = 0; j < N; j++){
            if(dp[i] == INF) continue;
            dp[i+AB[j].first] = min(dp[i+AB[j].first], dp[i] + AB[j].second);
        }
    }

    ll ans = INF;
    for(ll i = H; i < 191919; i++){
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;

}