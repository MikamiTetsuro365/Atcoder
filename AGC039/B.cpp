#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;

void dfs(ll idx, ll from = -1){
 
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //同じだったらもう処理しない
        //頂点に戻ってきたら
        //後戻りを許さない
        if(to == from){
            continue;
        }

        //下は例です．この跡に色々処理を書いて幸せになりましょう
        /*    
        if(G[idx][i].second % 2 == 0){
            ans[to] = ans[idx];
        }else{
            ans[to] = 1 - ans[idx];
        }
        */
 
        dfs(to, idx);
 
    }
}

//to (行き先), weight の順で設定
vector<vector<pair<ll, ll > > > G;
vector<ll > ans;
int main(){
    ll N;
    cin >> N;
    
    //初期化
    G.assign(N, vector<pair<ll, ll > >());
    ans.assign(N, 0);

    //グラフ入力
    for(ll i = 0; i < N-1; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
}