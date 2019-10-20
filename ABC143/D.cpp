#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N; cin >> N;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    ll ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            //a + b以上になる位置を検索
            ll t = vec[i] + vec[j];
            ll posi = lower_bound(vec.begin(), vec.end(), t) - vec.begin(); 
            //マイナス防止
            ans += max(posi - (j + 1), ll(0));
        }
    }

    cout << ans << endl;

}