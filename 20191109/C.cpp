#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M, L;
ll ans = 0;
ll INF = 1145141919191919;

vector<vector<pair<ll, ll> > > G;
 
vector<ll > dijkstra(ll start){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, INF);
    priority_queue<pair<ll, ll > , vector<pair<ll, ll > >, greater<pair<ll, ll > > > que;
    //初期化
    que.push(make_pair(0, start));
 
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
        
        for(ll i = 0; i < G[t_v].size(); i++){
            //大きいときは更新しない
            ll to = G[t_v][i].first;
            ll cost = d+G[t_v][i].second;
            if(dist[to] <= cost) continue;
            //累積距離と次の頂点
            que.push(make_pair(cost, to));
            //仮dist
            dist[to] = cost;
        }

        //現在の頂点から後退して0の辺を張る
        //LからRまでC出いけるならRからL以上R以下の頂点へはC出いける
        if(t_v-1 < 0 || dist[t_v-1] <= d) continue;
        que.push(make_pair(d, t_v-1));
        dist[t_v-1] = d;
        

    }   
    
    return dist;
 
} 
 
int main() {
    //頂点数
    cin >> N >> M;

    G.assign(N, vector<pair<ll, ll > >());
 
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G[u].push_back(make_pair(v, w));
    }

    vector<ll > dist = dijkstra(0);

    if(dist[N-1] == INF){
        cout << -1 << endl;
    }else{
        cout << dist[N-1] << endl;
    }
    

}
