#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;

ll ans = INF;
ll N, K;

ll POW[10];
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

void dfs(ll sum = 0, ll idx = 0, ll cn = 0){
    if(cn >= K){
        //cout << sum << endl;
        ll t_ans = 0;
        for(ll i = 9; i >= 0; i--){
            ll tmp = sum / (5 * POW[i]);
            t_ans += tmp;
            sum -= tmp *  (5 * POW[i]);

            tmp = sum / POW[i];
            t_ans += tmp;
            sum -= tmp *  POW[i];
        }
        ans = min(ans, t_ans);
        return;
    }
    if(idx >= vec.size()) return;
    //含める時
    dfs(sum + vec[idx], idx + 1, cn + 1);
    //含めない時
    dfs(sum, idx + 1, cn);
    return;
}


int main() {

    cin >> N >> K;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    for(ll i = 0; i <= 9; i++){
        POW[i] = fast_pow(10, i);
    }

    dfs();

    cout << ans << endl;

}