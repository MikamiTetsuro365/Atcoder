 #include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

ll bekijo[35];

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

    //準備
    for(ll i = 0; i <= 35; i++){
        bekijo[i] = fast_pow(2, i);
    }

    ll N;
    cin >> N;
    
    vector<ll > X(N+1, 0);
    for(ll i = 1; i <= N; i++){
        ll t; cin >> t;
        vec.push_back(t);
        X[i] = X[i-1] ^ t;
        //cout << X[i] << endl;
    }

    vector<vector<ll > > zeroSum(N+1, vector<ll >(32, 0));
    vector<vector<ll > > oneSum(N+1, vector<ll  >(32, 0));

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j <= 30; j++){
            if((vec[i] >> j) & 1 == 1){
                oneSum[i+1][j] += oneSum[i][j] + 1;
                zeroSum[i+1][j] += zeroSum[i][j];
            }else{
                zeroSum[i+1][j]+= zeroSum[i][j] + 1;
                oneSum[i+1][j] += oneSum[i][j];
            }
        }
    }  
    
    //計算
    for(ll i = 1; i <= N; i++){
        ll ans = 0;
        //cout << X[i] << endl;
        for(ll j = 0; j <= 30; j++){
            if((X[i] >> j) & 1 == 1){
                ans += zeroSum[i][j] * bekijo[j];
            }else{
                ans += oneSum[i][j] * bekijo[j];
            }       
        }
        cout << ans << endl;
    }
    
}

