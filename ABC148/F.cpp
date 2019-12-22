#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M, L;
ll ans = 0;

ll prohibitedArea;
ll mx;
vector<bool > seen;
vector<vector<pair<ll, ll> > > G;
vector<ll > prever;
 
vector<ll > dijkstra(ll start){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, 114514191919);
    prever.assign(N, -1);
    priority_queue<pair<ll, ll > , vector<pair<ll, ll > >, greater<pair<ll, ll > > > que;
    //初期化
    que.push(make_pair(0, start));
 
    //cout << que.top().first << endl;
 
    while(!que.empty()){
        //距離
        ll d = 0;
        //次の頂点
        ll t_v = 0;
        d = que.top().first;
        t_v = que.top().second;
        //topから削除
        que.pop();
        //探査済みなら処理しない
        if(used[t_v] == true) continue;
        //探査済みにする
        used[t_v] = true;
        //キューの上には既に最小距離が来ているので
        dist[t_v] = d;
        
        //次探査する頂点はt_vなのでt_vから更に次にの頂点の繋がりをキューにいれる
        for(ll i = 0; i < G[t_v].size(); i++){
            //もし探査済みの頂点で，そこまでの累積距離より今更新しようとしている距離が
            //大きいときは更新しない
            ll to = G[t_v][i].first;
            ll cost = d+G[t_v][i].second;
            if(dist[to] <= cost) continue;
            prever[to] = t_v;
            //累積距離と次の頂点
            que.push(make_pair(cost, to));
            //仮dist
            dist[to] = cost;
        }
        //cout << endl;
    }   
    
    return dist;
 
}

vector<ll > get_path(ll t){
    vector<ll > path;
    for(; t != -1; t = prever[t]){
        //cout << prever[t] << endl;
        path.push_back(t);
    }
    //reverse(path.begin(), path.end());
    return path;
}


void dfs(ll idx, ll from = -1, ll pathSize = 0){

    seen[idx] = true;

    if(idx == prohibitedArea){
        return;
    }

    mx = max(mx, pathSize);

    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i].first;
        //探査済み
        if(seen[to] == true){
            continue;
        }
        dfs(to , idx, pathSize + 1);
    }

    return;
}

int main() {
    //頂点数
    cin >> N >> M >> L;

    G.assign(N, vector<pair<ll, ll > >());
    seen.assign(N, false);
 
    for(ll i = 0; i < N-1; i++){   
        ll u, v, w;
        cin >> u >> v;
        w = 1;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));    
    }

    vector<ll > dist = dijkstra(M-1);
    //頂点0からget_path(ある頂点)までの経路
    vector<ll > path = get_path(L-1);

    //cout << dist[L-1] << endl;
    ll ans = dist[L-1] / 2 + dist[L-1] % 2;
    //cout << ans << endl;
    //cout << ans << endl;
    //できるだけ近づいて後一歩で捕まえられるという位置
    ll next_start = path[ans];
    //cout << next_start << endl;
    //後一歩で捕まえられるという位置には近づかずにどこまで逃げれるか
    prohibitedArea = path[ans - 1];
    //cout << prohibitedArea << endl;
    //dfs 
    
    dfs(next_start);

    ans += mx;

    cout << ans - 1 << endl;

}