#include "bits/stdc++.h"

using namespace std;
typedef unsigned long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

int main() {

    ll N;
    cin >> N;

    ll ans = INF;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(t % 2 == 1){
            cout << 0 << endl;
            return 0;
        }
        vec.push_back(t);
    }

    while(true){
        for(ll i = 0; i < N; i++){
            if(vec[i] % 2 == 1){
                cout << ans << endl;
                return 0;
            }
            vec[i] /= 2;
        }
        ans++;
    }

}