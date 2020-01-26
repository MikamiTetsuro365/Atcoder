#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

int main() {

    ll N, M;
    cin >> N >> M;
    
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.rbegin(), vec.rend());
    
    ll ans = 0;
    
    ll tmp = 0;
    for(ll i = 0; i < N; i++){
       tmp += vec[i];
       ans++;
       if(tmp >= M){
           cout << ans << endl;
           return 0;
       }
    }

}