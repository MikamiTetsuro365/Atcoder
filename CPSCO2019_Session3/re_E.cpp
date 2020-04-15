#include "bits/stdc++.h" 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

ll memo[50];
ll cn[591919][50][2];
ll X[591919];

ll fast_pow(ll a, ll n){
    if(n == 0) return 1;
    //べき数nが奇数, aを前にだして, a^n-1の気持ちに
    if(n % 2 == 1){
        return a * fast_pow(a, n - 1) % MOD;
    }else{
        //べき数nが偶数のとき，べき数を半分にして, aをまとめる. べき数を半分にする
        return fast_pow(a * a % MOD, n / 2) % MOD;
    }
}


int main() {

    ll N;
    cin >> N;

    //準備
    vec.assign(N+1919, 0);
    for(ll i = 0; i < 50; i++){
        memo[i] = fast_pow(2, i);
    }

    //入力と準備
    for(ll i = 1; i <= N; i++){
        cin >> vec[i];
        X[i] = vec[i] ^ X[i-1];
    }

    //準備(累積bit的な)
    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j < 50; j++){
            if((vec[i] >> j) & 1 == 1){
                cn[i][j][1] = cn[i-1][j][1] + 1;
                cn[i][j][0] = cn[i-1][j][0];
            }else{
                cn[i][j][0] = cn[i-1][j][0] + 1;
                cn[i][j][1] = cn[i-1][j][1];
            }
        }        
    }

    //計算
    for(ll i = 1; i <= N; i++){
        ll sum = 0;
        for(ll j = 0; j < 50; j++){
            if((X[i] >> j) & 1 == 1){
                sum += cn[i][j][0] * memo[j]; 
            }else{
                sum += cn[i][j][1] * memo[j];
            }
        }
        cout << sum << endl;
    }
} 