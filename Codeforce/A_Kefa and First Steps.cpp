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

    ll mx = 0;
    ll cn = 1;
    ll tmp = 0;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(i > 0){
            if(tmp <= t){
                cn++;
            }else{
                mx = max(cn, mx);
                cn = 1;
            }
        }
        tmp = t;
    }

    mx = max(cn, mx);

    cout << mx << endl;

}