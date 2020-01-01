#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

ll INF = 114514191919119;

int main(){

    ll N, K; cin >> N >> K;

    vector<ll > vec;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    sort(vec.rbegin(), vec.rend());

    ll ans = 0;

    for(ll i = 0; i < K; i++){
        ans+=vec[i];
    }

    cout << ans << endl;

}