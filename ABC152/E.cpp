#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll gcd(ll a, ll b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main() {

    ll N;
    cin >> N;

    ll l = 0;
    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        if(i != 0){
            l = lcm(vec[i],vec[i-1]);
        }
    }

    ll ans = 0;
    for(ll i = 0; i < N; i++){
        cout <<  l / vec[i] << endl;
        ans += l / vec[i];
        ans %= MOD;
    }

    cout << ans << endl;


}