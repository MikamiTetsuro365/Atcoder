#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll MOD = 1000000007;

int main(){

    ll N, M; cin >> N >> M;

    if(N + 1 < M || M + 1 < N){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;

    for(ll i = N; i > 0; i--){
        ans *= i;
        ans %= MOD;
    }
    for(ll i = M; i > 0; i--){
        ans *= i;
        ans %= MOD;
    }

    if(N == M){
        ans *= 2;
        ans %= MOD;
    }

    cout << ans << endl;

}