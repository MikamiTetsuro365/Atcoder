#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main(){

    ll N; cin >> N;

    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        vec.push_back(t);
    }

    vector<ll > a(N, 0);
    for(ll i = 1; i < N; i++){
        a[i] += vec[i-1] + a[i-1];
       //cout << a[i] << endl;
    }
    vector<ll > b(N, 0);
    for(ll i = N-2; i >= 0; i--){
        b[i] += vec[i+1] + b[i+1];
        //cout << b[i] << endl;
    }

    ll ans = 1145141919191919;
    for(ll i = 1; i < N; i++){
        //cout << a[i] << " " << b[i-1] << endl;
        ans = min(ans, abs(a[i] - b[i-1]) );
    }

    cout << ans << endl;
    

}