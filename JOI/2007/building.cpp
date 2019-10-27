#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;

int main(){

    ll N; cin >> N;
    vector<ll > b(N, 0);
    for(ll i = 0; i < N; i++){
        cin >> b[i];
    } 

    ll ans = 1;
    //必ずビルは1つ使われるので初期値は1
    vector<ll > dp(N, 1);
    //dp[0]= 0;

    for(ll j = 0; j < N; j++){
        for(ll k = j + 1; k < N; k++){
            //大きくなければ飛ばす
            if(b[j] >= b[k]) continue;
            dp[k] = max(dp[j] + 1, dp[k]);
        }
        //順番に確認
        ans = max(dp[j], ans);
    }        
    cout << ans << endl;
}