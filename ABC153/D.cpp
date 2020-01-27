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

    ll H;
    cin >> H;

    ll ans = 1;

    for(ll i = H; i >= 1; i /= 2){
        ans *= 2;
        //cout << i << endl;
    }

    cout << ans - 1 << endl;

}