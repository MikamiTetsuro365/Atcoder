#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

int main(){
    ll N, K;
    cin >> N >> K;
    
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        if(t >= K){
            ans++;
        }
    }

    cout << ans << endl;

}