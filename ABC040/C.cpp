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

    vector<ll > A(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    vector<ll > dp(N+10, INF);
    dp[0] = 0;

    for(ll i = 0; i < N; i++){
        dp[i+1] =  min(dp[i+1], dp[i] + abs(A[i]-A[i+1]));
        dp[i+2] =  min(dp[i+2], dp[i] + abs(A[i]-A[i+2]));

    }
    cout << dp[N-1] << endl;;
}