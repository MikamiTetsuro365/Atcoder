#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, M, K;
    cin >> N >> M >> K;

    ll value = 0;
    //余白大事
    vector<vector<ll > > dp(N + 1, vector<ll >(M + 1, 0));

    for(ll i = 0; i < K; i++){
        ll x, y; cin >> x >> y;
        dp[x-1][y-1] = -1;
    }

    dp[0][0] = 1;
    for(ll x = 0; x < N; x++){
        //cout << x << endl;
        for(ll y = 0; y < M; y++){
            //cout << y << endl;
            if(dp[x][y] == -1) continue;
            if(dp[x+1][y] != -1 && x+1 < N) dp[x+1][y] += dp[x][y];
            if(dp[x][y+1] != -1 && y+1 < M) dp[x][y+1] += dp[x][y];
            
        }    
    }
    /*
    for(ll x = 0; x < N; x++){
        for(ll y = 0; y < M; y++){
            cout << dp[x][y] << "  ";
        }    
        cout << endl;
    }
    */
    
    cout << dp[N-1][M-1] << endl;



}