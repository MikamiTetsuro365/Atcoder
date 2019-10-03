#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){

    ll N, M;
    cin >> N >> M;

    vector<ll > day(N, -1);

    for(ll i = 0; i < M; i++){
        ll d, p;
        cin >> d >> p;
        day[d] = p;
    }

    ll value = 0;
    vector<vector<ll > > dp(N + 1, vector<ll >(3, value));
    dp[0][0] = 1;

    vcector<ll > used(3, 0);

    for(ll i = 1; i < N; i++){
        for(ll j = 0; j < 3; j++){
            if(used[j] < 3){
                dp[i] +=  
            }
        }
    } 



}