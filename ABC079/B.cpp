#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N = 0;
    cin >> N;
    ll l1 = 2;
    ll l2 = 1;

    ll ans = 0;

    for(ll i = 2; i <= N; i++){
        ll t_l = l1 + l2;
        l1 = l2;
        l2 = t_l;
    }

    cout << l2 << endl;
}