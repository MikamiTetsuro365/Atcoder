#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

//XOR系はbitごとに独立して考える
//２進数の足し算をしっかりイメージする 1 + 2 + 4 + 8....
ll fast_pow(ll a, ll n, ll mod = MOD){
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

    ll N; cin >> N;
    vector<ll > A(N, 0);

    for(ll i = 0; i < N; i++){
        cin >> A[i];
    }

    ll sum = 0;

    vector<vector<ll > > memo(60, vector<ll >(2, 0));
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < 60; j++){
            if((A[i] >> j) & 1 == 1){
                memo[j][1]++;
            }else{
                memo[j][0]++;
            }
        }
    }

    //算出
    for(ll j = 0; j < 60; j++){
        sum += fast_pow(2, j) * (memo[j][0] * memo[j][1] % MOD) % MOD;
        sum %= MOD;
    }
    cout << sum << endl;

}