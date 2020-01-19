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

    ll N;
    cin >> N;

    for(ll i = 0; i < N - 1; i++){
        ll a; cin >> a;
        vec.push_back(a);
    }

    ll ans = vec[0];
    for(ll i = 0; i < N - 2; i++){
        if(vec[i] > vec[i + 1]){
            ans += vec[i + 1];
        }else{
            ans += vec[i];
        }
    }
    ans += vec[N-2];

    cout << ans << endl;

}