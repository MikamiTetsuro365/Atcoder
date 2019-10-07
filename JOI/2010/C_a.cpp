#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M;
ll ans = 0;
vector<vector<pair<ll, ll> > > G;
 
void dijkstra(ll start){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, 1<<28);
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
            if(dist[G[t_v][i].first] <= d+G[t_v][i].second) continue;
            //累積距離と次の頂点
            que.push(make_pair(d+G[t_v][i].second, G[t_v][i].first));
        }
    }   
 
    //確認
    for(ll i = 0; i < N; i++){
        //cout << i << " " << dist[i] << endl;
        if(dist[i] > 0 && dist[i] <= 2){
            ans++;
        }
    }
 
}
 
int main() {
    //頂点数
    cin >> N >> M;
    G.assign(N, vector<pair<ll, ll > >());
 
    for(ll i = 0; i < M; i++){   
        ll u, v;
        ll w = 1;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        //make_pair(重み,貼りたい辺の先の頂点)
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));    
    }
 
    dijkstra(0);
 
    //dijkstra(1);
 
    cout << ans << endl;
 
}