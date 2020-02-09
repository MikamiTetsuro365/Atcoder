#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N, NG1, NG2, NG3;
    cin >> N >> NG1 >> NG2 >> NG3;

    vector<ll > dp(N+19, INF);
    dp[0] = 0;

    for(ll i = 0; i < N; i++){
        if(dp[i] == INF) continue;
        if(dp[i] >= 100) continue;
        for(ll j = 1; j <= 3; j++){
            if(i+j == NG1 || i+j == NG2 || i+j == NG3) continue;
            dp[i+j] = min(dp[i+j], dp[i]+1);
        }
    }

    if(dp[N] <= 100){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}