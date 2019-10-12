#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

int main(){

    ll N;
    cin >> N;

    map<ll, ll > mp;
    for(ll i = 0; i < N; i++){
        ll t = 0; cin >> t;
        mp[t]++;
    }

    ll n = 0;
    if(N % 2 == 0){
        n = 1;
    }

    ll ans = 1;
    //奇数のとき中央の人は固定，偶数のとき全員に2通りの並べ方がある
    auto begin = mp.begin(), end = mp.end();
    for (auto iter = begin; iter != end; iter++) {
        ll k = iter->first;
        ll h = iter->second;

        if(k == n){
            if(k == 0 && h == 1){

            }else if(k > 0 && h == 2){
                ans *= 2;
                ans %= MOD;
            }else{
                cout << 0 << endl;
                return 0;            
            }

        }else{
            cout << 0 << endl;
            return 0;          
        }

        n += 2;
    }

    cout << ans << endl;

}