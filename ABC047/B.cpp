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

    ll W, H, N;
    cin >> W >> H >> N;

    ll x1 = 0;
    ll x2 = W;
    ll y1 = 0;
    ll y2 = H;

    for(ll i = 0; i < N; i++){
        ll x, y, a;
        cin >> x >> y >> a;
        if(a == 1) x1 = max(x1, x);
        else if(a == 2) x2 = min(x2, x);
        else if(a == 3) y1 = max(y1, y);
        else if(a == 4) y2 = min(y2, y);
    }

    if((x2-x1) < 0 || (y2-y1) < 0){
        cout << 0 << endl;
    }else{
        ll ans = (x2-x1) * (y2-y1);
        cout << ans << endl;
    }    
}