#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll N, K; cin >> N >> K;

    vector<ll > vec(N, 0);
    vector<ll > ruiseki(N+1, 0);
    ll ans = 0;

    for(ll i = 0; i < N; i++){
        cin >> vec[i];
    }

    for(ll i = 0; i < N; i++){
        if(i == 0) ruiseki[1] = vec[0];
        else ruiseki[i+1] = ruiseki[i] + vec[i];
    }


    for(ll i = K; i <= N; i++){
        ans += ruiseki[i] - ruiseki[i-K];
    }

    cout << ans << endl;


}