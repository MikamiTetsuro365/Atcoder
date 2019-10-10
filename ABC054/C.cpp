#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  

//to (行き先), weight の順で設定
ll ans = 0;

void dfs(vector<vector<pi > > G, vector<bool > seen, ll idx, ll from = -1){
    seen[idx] = true;

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //同じだったらもう処理しない
        //頂点に戻ってきたら
        //後戻りを許さない
        if(seen[to] == true){
            continue;
        }
 
        dfs(G, seen ,to , idx);
 
    }

    bool f = true;
    for(ll i = 0; i < seen.size(); i++){
        if(seen[i] == false){
            f = false;
            break;
        } 
    }

    if(f == true) ans++;

}

int main(){
    ll N, M;
    cin >> N >> M;
    
    //初期化
    vector<vector<pi > > G;
    G.assign(N, vector<pi >());
    vector<bool > seen(N, false);
 
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

    dfs(G ,seen ,0);

    cout << ans << endl;

}