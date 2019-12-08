#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
//bitDPです
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
    //頂点数
    ll N, M;
    cin >> N >> M;

    //コスト
    vector<ll > A(M,0);
    //入力個数
    vector<ll > B(M,0);
    //箱との対応
    vector<ll > C(M,0);

    for(ll i = 0; i < M; i++){
        cin >> A[i] >> B[i];
        for(ll j = 0; j < B[i]; j++){
            ll t; cin >> t;
            t--;
            //ビットに表した時の数
            C[i] += 1<<t;
        }
    }

    //2^12 = 4096 最大
    ll limit = fast_pow(2, 12);
    vector<vector<ll > > dp(M + 1919, vector<ll >(limit, INF));
    dp[0][0] = 0;

    for(ll i = 0; i < M; i++){
        for(ll j = 0; j < (1<<N); j++){
            if(dp[i][j] == INF) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

            ll next = j | C[i];

            dp[i + 1][next] = min(dp[i][j] + A[i],  dp[i + 1][next]);
            
            //cout << next << " " << dp[i + 1][next] << endl;
        }        
    }

    //(1<<N)-1 全部立っていますか？
    if(dp[M][(1<<N)-1] == INF){
        cout << -1 << endl;
    }else{
        cout << dp[M][(1<<N)-1] << endl;
    }

    
}