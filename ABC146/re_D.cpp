#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
vector<vector<pi > > G;
vector<bool > seen;
vector<ll > ans;
ll color_mx = -1;
//辺をデータとして持っておく
map<pi, ll> edge;

void dfs(ll idx, ll from = -1){
    seen[idx] = true;
    //始点の前には辺がない
    if(from == -1){
        edge[make_pair(from, idx)] = -1;
    }

    ll cn = 1;
    for(ll i = 0; i < G[idx].size(); i++){

        //次の行き先は？
        ll to = G[idx][i].first;
        //edge番号は？
        ll edge_num = G[idx][i].second;
        //探査済み
        if(seen[to] == true){
            continue;
        }
        //前の辺が同じ色だったら同じ色には塗らない
        if(edge[make_pair(from, idx)] == cn){
            cn++;
        }
        //どこからどこへ向かう辺が何色で塗られたかを記録しておく
        edge[make_pair(idx, to)] = cn;
        //cout << t_from << " " << cn << endl;
        ans[edge_num ] = cn;
        cn++;
        dfs(to , idx);
    }

    color_mx = max(cn-1, color_mx);

}

int main(){
    ll N;
    cin >> N;
    //初期化
    G.assign(N, vector<pi >());
    seen.assign(N, false);
    ans.assign(N - 1, 0);
    
    //グラフ入力
    for(ll i = 0; i < N - 1; i++){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        //重みとして今現在貼った辺が何個目の辺であるかを記憶しておく
        G[u].push_back(make_pair(v, i));
        G[v].push_back(make_pair(u, i));
    }

    dfs(0);

    cout << color_mx << endl;

    for(ll i = 0; i < N - 1; i++){
        cout << ans[i] << endl;
    }

}