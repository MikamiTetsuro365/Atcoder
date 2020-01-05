#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N; cin >> N;

    vector<ll > dp(N+19, INF);

    dp[0] = 0;

    for(ll i = 0; i < N; i++){

        if(dp[i] == INF) continue;

        dp[i + 1] = min(dp[i] + 1, dp[i + 1]);

        ll cn = 0;
        while(true){
            if(i + pow(6, cn) > N){
                break;
            }
            dp[i + pow(6, cn)] = min(dp[i] + 1, dp[i + pow(6, cn)]);
            cn++;
        }
        cn = 0;
        while(true){
            if(i + pow(9, cn) > N){
                break;
            }
            dp[i + pow(9, cn)] = min(dp[i] + 1, dp[i + pow(9, cn)]);
            cn++;
        }
    }

    cout << dp[N] << endl;

}