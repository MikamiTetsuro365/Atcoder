#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
//逆から塗っていくことを考える
//すでにある頂点である半径だけ塗られていたら無駄処理なので塗らない
//ある頂点を塗る必要がない＝ある頂点はすでにある深さ(半径)だけ他の色で塗られている
vector<vector<pi > > G;
//ある頂点に対してある深さで色を塗られているか
//ある深さで塗られていればそれ以上深い
vector<vector<bool > > filled;
//今までに参照したかどうか
vector<bool > seen;
vector<ll > ans;
vector<ll > V;
vector<ll > D;
vector<ll > C;

ll N, M, Q;
//ll d;
ll c;

void dfs(ll idx , ll depth = 0, ll from = -1){

    if(filled[idx][depth] == true){
        return;
    }

    if(ans[idx] == 0){
        ans[idx] = c;
    }

    //見た
    //seen[idx] = true;
    filled[idx][depth] = true;

    if(depth == 0) return;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //探査済み
        //if(seen[to] == true) continue;
        //すでにある半径だけ頂点toが塗られていたら塗るのは無駄なので塗らない
        if(filled[to][depth - 1] == true) continue;

        dfs(to , depth - 1 ,idx);
    }

    return;
}

int main(){
    cin >> N >> M;
    //初期化
    G.assign(N, vector<pi >());
    filled.assign(N, vector<bool >(11, false));
    ans.assign(N, 0);
 
    //グラフ入力
    for(ll i = 0; i < M; i++){
        ll u, v, w;
        w = 0;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }

    //クエリ入力
    cin >> Q;
    V.assign(Q, 0);
    D.assign(Q, 0);
    C.assign(Q, 0);

    for(ll i = 0; i < Q; i++){
        cin >> V[i] >> D[i] >> C[i];
        V[i]--;
    }

    //後ろから塗っていく
    for(ll i = Q - 1; i >= 0; i--){
        seen.assign(N, false);
        //d = D[i];
        c = C[i];

        dfs(V[i], D[i]);
    }

    for(ll i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    
}