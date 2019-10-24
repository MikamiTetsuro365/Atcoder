#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M;

int main(){

    cin >> N >> M;
    vector<vector<ll > > cost(N, vector<ll >(3, 0));
    vector<vector<ll > > c_cost(N, vector<ll >(3, 0));
    //前処理
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            char t = 0; cin >> t;
            if(t == 'W'){
                cost[i][0]++;
            }else if(t == 'B'){
                cost[i][1]++;
            }else{
                cost[i][2]++;
            }
            //w
            c_cost[i][0] = cost[i][1] + cost[i][2];
            //B
            c_cost[i][1] = cost[i][0] + cost[i][2];
            //R
            c_cost[i][2] = cost[i][0] + cost[i][1];

        }       
    }

    ll ans = 0;
    vector<vector<ll > > dp(N+1, vector<ll >(3, INF));
    //一行目は白にしか変更できない
    dp[0][0] = c_cost[0][0];
    for(ll i = 0; i < N - 1; i++){
        for(ll j = 0; j < 3; j++){
            if(dp[i][j] == INF) continue;
            //同じ色から同じ色へ変更するコスト
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + c_cost[i + 1][j]);
            if(j == 2) continue;
            //違う色へ変更するコスト
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + c_cost[i + 1][j+1]);
        }

    }
    cout << dp[N - 1][2] << endl;
}