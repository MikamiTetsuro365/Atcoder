#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll sum; cin >> sum;

    for(ll i = 0; i < 9; i++){
        ll price; cin >> price;
        sum -= price;
    }

    cout << sum << endl;

}