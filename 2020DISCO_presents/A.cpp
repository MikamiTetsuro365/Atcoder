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

    ll X, Y; cin >> X >> Y;

    map<ll, ll> kane;

    kane[0] = 300000;
    kane[1] = 200000;
    kane[2] = 100000;

    

    ll ans = kane[X-1] + kane[Y-1];

    if(X == 1 && Y == 1){
        ans += 400000;
    }

    cout << ans << endl;

}