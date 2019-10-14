#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;
    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll r, l; cin >> l >> r;
        ans += r - l + 1;
    }

    cout << ans << endl;

}