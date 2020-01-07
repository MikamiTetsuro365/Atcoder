#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;


int main() {

    ll N, C; cin >> N >> C;

    //入力
    vector<pi > input;

    for(ll i = 0; i < N; i++){
        ll x, v; cin >> x >> v;
        input.push_back(make_pair(x, v));
    } 

    //時計回り累積和と最大値
    //コストの累積ワと距離を記憶
    vector<pi > sum(N + 1);
    vector<ll > mx(N + 1, 0);

    ll tmp = -INF;
    //現在地
    sum[0].first = 0; sum[0].second = 0;
    mx[0] = 0; 
    for(ll i = 1; i <= N; i++){
        ll x = input[i - 1].first;
        ll v = input[i - 1].second;
        if(i == 1){
            sum[i].first = v - x;
            sum[i].second = x;
        }else{
            //進んだ距離(x - sum[i-1].second)
            sum[i].first = sum[i-1].first + (v - (x - sum[i-1].second));
            sum[i].second = x;
        }
        
        ll m = max(sum[i].first, tmp);
        mx[i] = m;
        tmp = m;

    }

    //反時計回り累積和と最大値
    vector<pi > r_sum(N+1);
    vector<ll > r_mx(N+1, 0);

    ll idx = 1;
    tmp = -INF;
    //現在地
    r_sum[0].first = 0; r_sum[0].second = 0;
    r_mx[0] = 0; 
    for(ll i = N - 1; i >= 0; i--){
        ll x = C - input[i].first;
        ll v = input[i].second;
        if(i == N - 1){
            r_sum[idx].first = v - x;
            r_sum[idx].second = x;
        }else{
            //(x-r_sum[idx-1].second)進んだ距離
            r_sum[idx].first = r_sum[idx-1].first + (v - (x-r_sum[idx-1].second));
            r_sum[idx].second = x;
        }
        
        ll m = max(r_sum[idx].first, tmp);
        r_mx[idx] = m;
        tmp = m;
        idx++;
    }

    //確認
    
    /*
    for(ll i = 0; i <= N; i++){
        cout << sum[i].first << " " << sum[i].second << " " << mx[i] << endl;
    } 
    */ 
    /*
    for(ll i = 0; i <= N; i++){
        cout << r_sum[i].first << " " << r_sum[i].second << " " << r_mx[i] << endl;
    }
    */
    

    //時計回りで全探査
    //あるところで折り返して反対時計回りに寿司をとっていった時どこが最大か
    //折り返さなくて最大のときもある

    ll ans = -INF;

    for(ll i = 0; i <= N; i++){
        //寿司を時計回りに食べるだけ食べて折り返さずに退店するとき
        ll not_turn = sum[i].first;

        //cout << not_turn << endl;

        //折り返して反対側へ寿司を食べに行く時
        //コスト-折返し距離
        ll turn = sum[i].first - sum[i].second;
        ll idx = N - i;
        //cout << r_mx[idx] << endl;
        turn += r_mx[idx];
        
        ans = max(ans, turn);
        ans = max(ans, not_turn);
    }

    //反時計回りで全探査
    for(ll i = 0; i <= N; i++){
        //寿司を反時計回りに食べるだけ食べて折り返さずに退店するとき
        ll not_turn = r_sum[i].first;

        //cout << not_turn << endl;

        //折り返して反対側へ寿司を食べに行く時
        //コスト-折返し距離
        ll turn = r_sum[i].first - r_sum[i].second;
        ll idx = N - i;
        //cout << mx[idx] << endl;
        turn += mx[idx];
        
        ans = max(ans, turn);
        ans = max(ans, not_turn);
    }

    cout << ans << endl;

}