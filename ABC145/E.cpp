#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll N, T; cin >> N >> T;

    vector<pi> AB;

    for(ll i = 0; i < N; i++){
        ll A, B; cin >> A >> B;
        AB.push_back(make_pair(A, B));
    }

    sort(AB.begin(), AB.end());

    vector<vector<ll > > dp(N+1010, vector<ll >(T+3010, 0));
    dp[0][0] = 0;

    ll ans = -1;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j <= T-0.5; j++){
            if(dp[i][j] != -1){
                dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
                dp[i+1][j+AB[i].first] = max(dp[i][j]+AB[i].second, dp[i+1][j+AB[i].first] );
                ans = max(ans, dp[i+1][j+AB[i].first]);
            }
        }
    }
    cout << ans << endl;
}