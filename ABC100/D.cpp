#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
//絶対値なので普通の動的計画法では無理
//答えが大きくなるにはプラス方向で大きくなるように選ぶかマイナス方向で大きくなるように選ぶかを考えると良い
//綺麗さ 美味しさ　人気度をそれぞれプラスまたはマイナスのどちらで大きくたら最終的に大きくなるか考える

int main(){

    ll N, M; cin >> N >> M;

    vector<vector<ll > > dp(N+1, vector<ll >(M+19, -INF));
    dp[0][0] = 0;

    ll ans = -INF;
    for(ll i = 0; i < N; i++){
        ll x, y, z; cin >> x >> y >> z;
        ll tmp = abs(x) + abs(y) + abs(z);
        for(ll j = 0; j <= M; j++){
            if(dp[i][j] == -INF) continue;
            
            dp[i+1][j] = max(dp[i][j], dp[i+1][j]);

            if(j+1 <= M){
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + tmp);
            }

            if(j+1 == M){
                ans = max(dp[i+1][j+1], ans);
            }
        }
    }

    cout << ans << endl;

}