#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N, M;
    cin >> N >> M;

    
    vector<ll > in(N + 2, 0);
    for(ll i = 1; i <= N; i++){
        cin >> in[i];
    }

    ll ans = 0;
    ll k_ans = 0;
    ll g_ans = 0;
    //奇数番だけ食べ続ける
    for(ll i = 1; i <= N; i++){
        ll l = in[i-1] + in[i] - M;
        //ll r = in[i+1] + in[i] - M;
        ans += max(l, ll(0));
        in[i] -= max(l, ll(0));
        //cout << in[i] << " ";
    }

    cout << ans << endl;


}