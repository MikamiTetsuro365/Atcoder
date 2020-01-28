#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
ll H, N;

int main() {

    ll N;
    cin >> N;

    ll ans = 0;
    ll bai = 1;

    for(ll i = 0; i < N; i++){
        char c; ll a;
        cin >> c >> a;
        if(c == '+') ans += a;
        if(c == '*' && a != 0) bai *= a;
    }

    cout << ans * bai << endl;

}