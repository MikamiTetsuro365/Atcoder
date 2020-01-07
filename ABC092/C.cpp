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

    ll N; cin >> N;

    vec.push_back(0);
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        vec.push_back(t);
    }
    vec.push_back(0);

    vector<ll > r;

    //累積和
    for(ll i = 0; i < vec.size(); i++){
        if(i == 0) r.push_back(vec[i]);
        else r.push_back(r[i-1] + abs(vec[i-1] - vec[i]));
        
        //cout << r[i] << endl;
    }

    for(ll i = 1; i <= N; i++){
        //この間だけ累積和無効
        ll jump = abs(vec[i-1]-vec[i+1]);
        ll ans = r[i-1] + jump + (r[N+1] - r[i+1]);
        cout << ans << endl;
    }

    //cout << ans << endl;

}