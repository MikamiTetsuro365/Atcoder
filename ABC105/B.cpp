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
    ll N; cin >> N;
    vector<string > dp(N+100, "No");
    dp[0] = "Yes";
    for(ll i = 0; i < N; i++){
        if(dp[i] != "No"){
            dp[i+4] = "Yes";
            dp[i+7] = "Yes";
        }
    }

    cout << dp[N] << endl;
    
    return 0;

}
