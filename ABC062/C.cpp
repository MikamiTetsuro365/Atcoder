#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll ans = INF;


void solv(ll H, ll W){

    for(ll i = 1; i < W; i++){
        //縦横横
        ll a = i * H;
        ll b = H/2*(W-i);
        ll c = H * W - a - b;
        ans = min(ans, abs(max(max(a, b), c)-min(min(a, b), c)));
        //縦縦縦
        ll d = (W-i)/2 * H;
        ll e = H * W - a - d;
        ans = min(ans, abs(max(max(a, d), e)-min(min(a, d), e)));
    }
}

int main() {

    ll H, W;
    cin >> H >> W;

    if(H % 3 == 0 || W % 3 == 0){
        cout << 0 << endl;
        return 0;
    }

    solv(H, W);
    swap(H, W);
    solv(H, W);

    cout << ans << endl;

}