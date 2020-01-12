#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

int main() {

    ll N;
    cin >> N;

    ll ans = 0;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        if(i == 0) ans = t;
        else ans = lcm(max(ans,t), min(ans, t));
    }

    cout << ans << endl;

}