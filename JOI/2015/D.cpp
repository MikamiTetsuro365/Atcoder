#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, M;
    cin >> N >> M;

    vector<ll > city(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> city[i];
    }

    vector<ll > cost(M, 0);

    for(ll i = 0; i < M; i++){
        cin >> cost[i];
    }

    
    vector<vector<ll > > dp(M + 1, vector<ll >(N + 1, 1145141919));
    dp[0][0] = 0;

    //答え
    ll ans = 1145141919;

    for(ll i = 0; i < M ; i++){
        for(ll j = 0; j < N; j++){
            ll next_city = j + 1;
            if(dp[i][j] == 1145141919) continue;
            ll t_cost = city[j] * cost[i];
            //cout << t_cost << endl;
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i+1][j+1] = min(dp[i+1][next_city], dp[i][j] + t_cost);
        }
    }

    for(ll i = 0; i <= M; i++){
        ans = min(dp[i][N], ans);
    }

    cout << ans << endl;

}