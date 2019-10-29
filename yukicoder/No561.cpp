#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, C; cin >> N >> C;

    vector<vector<ll > > dp(105, vector<ll >(2, -1));
    dp[0][0] = 0;

    for(ll i = 0; i < N; i++){
        ll t, k; cin >> t >> k;
        for(ll j = 0; j < 2; j++){
            if(dp[i][j] == -1) continue;

            if(j == 0){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + t);
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + k - C);
            }else{
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + k);
                dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + t - C);              
            }
        }
    }

    cout << max(dp[N][0], dp[N][1]) << endl;

}