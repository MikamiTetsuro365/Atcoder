#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;

ll INF = 1145141919454519;

ll mod = 1e9 + 7;

ll ruijo[61];

ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1) % mod;
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a % mod, n / 2) % mod;
    }
}


int main() {

    ll N;
    cin >> N;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    for(ll i = 0; i <= 60; i++){
        ruijo[i] = fast_pow(2, i);
    }

    vector<vector<ll > > zero_sum(N + 19, vector<ll >(61, 0));
    vector<vector<ll > > one_sum(N + 19,  vector<ll >(61, 0));

    for(ll i = 0; i < N; i++){
        //cout << vec[i] << endl;
        for(ll j = 0; j <= 60; j++){
            if((vec[i]>>j) & 1 == 1){
                //cout << 1 ;
                zero_sum[i + 1][j] = zero_sum[i][j];
                one_sum[i + 1][j] = one_sum[i][j] + 1;
            }else{
                //cout << 0 ;
                one_sum[i + 1][j] = one_sum[i][j];
                zero_sum[i + 1][j] = zero_sum[i][j] + 1;
            }
        }
    }

    ll ans = 0;
    
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j <= 60; j++){
            if((vec[i]>>j) & 1 == 1){
                ll num = zero_sum[N][j] - zero_sum[i+1][j];
                ans += ruijo[j] * num % mod;
                ans %= mod;
            }else{
                ll num = one_sum[N][j] - one_sum[i+1][j];
                ans += ruijo[j] * num % mod;
                ans %= mod;
            }
        }
    }

    cout << ans << endl;
    
}