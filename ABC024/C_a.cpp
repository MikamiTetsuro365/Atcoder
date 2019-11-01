#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, D, K; cin >> N >> D >> K;
    vector<pi> plan;

    for(ll i = 0; i < D; i++){
        ll x, y; cin >> x >> y;
        plan.push_back(make_pair(x, y));
    }

    vector<ll > all_ans;
    for(ll k = 0; k < K; k++){
        ll s, e; cin >> s >> e;
        ll ans = 0;
        
        all_ans.push_back(ans+1);
    }

    for(ll i = 0; i < all_ans.size(); i++){
        cout << all_ans[i] << endl;
    }


}