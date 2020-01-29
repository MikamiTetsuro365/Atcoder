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

    ll N, T;
    cin >> N >> T;
    
    ll ans = 0;
    ll cn = 0;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(ans <= t){
            ans = t;
        }else{
            cn = (ans - t) / T;
            if((ans - t) % T > 0) cn++;
            ans = t + cn * T;
        }
    }

    cout << ans << endl;
}