#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main(){

    ll N;
    cin >> N;

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll M; cin >> M;
        ans += max(80LL - M, 0LL);
    }

    cout << ans << endl;

}