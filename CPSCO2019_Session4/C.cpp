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

    ll N, D;
    cin >> N >> D;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        ll choka = upper_bound(vec.begin(), vec.end(), vec[i]+D) - vec.begin();
        ll ika_num = choka - 1 - i;
        //cout << ika - i << endl;
        if(ika_num < 2) continue;
        ans += ika_num * (ika_num-1) / 2;
    }

    cout << ans << endl;
}