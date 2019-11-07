#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1e15;

int main(){

    ll N, M, K; cin >> N >> M >> K;

    vector<ll > Orange(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> Orange[i];
    }

    vector<ll > dp(N+100, INF);
    dp[0] = 0;

    for(ll i = 0; i < N; i++){
        ll mx = Orange[i];
        ll mn = Orange[i];
        for(ll j = 0; j < M; j++){
            if(i + j > N) break;
            if(Orange[i + j] < mn) mn = Orange[i + j];
            if(Orange[i + j] > mx) mx = Orange[i + j];
            //cout << endl;
            /*
            if(dp[i+j] == INF){
                dp[i+j] = K + (j + 1) * (mx - mn);
            }else{
                dp[i+j] = min(K + (j + 1) * (mx - mn) + dp[i], dp[i+j]);
            }
            */
            //cout << mn << " " << mx << endl;
            dp[i+j+1] = min(K + (j+1) * (mx - mn) + dp[i], dp[i+j+1]);
            //cout << K + (j + 1) * (mx - mn) << endl;
        }
    }

    cout << dp[N] << endl;
}