#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
vector<vector<pi > > G;
vector<bool > seen;
ll MOD = 1000000007;
ll N, M;
//ある頂点を固定して
//それを白または黒で塗った時の他の頂点の塗り方の通りの数を足し算する
//http://wk1080id.hatenablog.com/entry/2018/02/20/135453
ll dp[191919][2];

//color = 0　白 color = 1 黒
ll dfs(ll idx, ll color, ll from = -1){

    //すでに更新済み
    if(dp[idx][color] >= 0) return dp[idx][color];

    //初期化
    dp[idx][color] = 1;
    
    seen[idx] = true;
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll cn = 0;
        ll to = G[idx][i].first;
        //木なので元の場所には戻らないようにする
        if(to == from){
            continue;
        } 
        //白で濡れる数
        cn += dfs(to ,0 ,idx);
        cn %= MOD;
        //黒->黒へは濡れない
        //白->黒へ遷移する数
        if(color != 1){
            cn += dfs(to , 1, idx);
            cn %= MOD;
        }
        //通りの数なので掛け算
        dp[idx][color] *= cn;
        dp[idx][color] %= MOD;

    }
    //cout << idx << " " << from << " " << dp[idx][color] << endl;
    return dp[idx][color];
}

int main(){
    
    cin >> N;
    //初期化
    G.assign(N, vector<pi >());
    seen.assign(N, false);

    for(ll i = 0; i <= N; i++){
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    //dp[0][0] = 1;
    //dp[0][1] = 1;
 
    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v, w;
        w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    //dfs(0);
    ll w = dfs((ll)0, (ll)0);
    ll b = dfs((ll)0, (ll)1);


    cout << (w + b) % MOD << endl;
    
}