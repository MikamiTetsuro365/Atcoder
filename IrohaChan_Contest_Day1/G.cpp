#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194;
//dp[i][j] = i日目に好意をほのめかし、今までj回好意をほのめかしているときの、機嫌の最大値
//配る系?
//あるご機嫌値を何回目に採用するかを配っていく
//N-M<=Kだったら必ず最大値が求まるはずなので，どのような配り方をすれば最大になるかを考える
//貪欲にやるなら選ぶ選ばないを繰り返す->dfs->こでやるとメモ化再帰につながる
int main(){

    ll N, M, K;
    cin >> N >> M >> K;

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        vec.push_back(t);
    }

    vector<vector<ll > > dp(N+19, vector<ll >(M+19, -INF));
    //初めのK日はご機嫌をとる可能性がある
    for(ll i = 0; i < K; i++) dp[i][0] = 0;
    //dp[0][0] = 0;

    for(ll i = 0; i < N; i++){
        //何回目に褒めるか
        for(ll m = 0; m < M; m++){
            //ほめたのちK日以内のうちにほめなければいけない
            if(dp[i][m] == -INF) continue;
            for(ll k = 1; k <= K; k++){
                ll next = i + k;
                //N日を超えちゃだめ
                if(next > N) continue;
                dp[next][m+1] = max(dp[next][m+1], dp[i][m] + vec[i]);
            }
        }
    }

    //N日間でM回ほめきれたか
    if(dp[N][M] == -INF) cout << -1 << endl;
    else cout << dp[N][M] << endl;

}