#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};

int main(){

    ll A, B; cin >> A >> B;

    ll ans = max(ll(0), A - B * 2);

    cout << ans << endl;


}