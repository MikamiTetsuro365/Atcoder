#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//2日酔のときに出場しなくてよかった
int main(){

    ll A, B, M;
    cin >> A >> B >> M;

    vector<ll > a(A, 0);
    vector<ll > b(B, 0);

    ll ans = INF;

    ll mna = INF;
    for(ll i = 0; i < A; i++){
        cin >> a[i];
        mna = min(a[i], mna);
    }

    ll mnb = INF;
    for(ll i = 0; i < B; i++){
        cin >> b[i];
        mnb = min(b[i], mnb);
    }

    ans = mna + mnb;
    for(ll i = 0; i < M; i++){
        ll x, y, c; cin >> x >> y >> c;
        ans = min(ans,a[x-1]+b[y-1]-c);
    }

    cout << ans << endl;

}