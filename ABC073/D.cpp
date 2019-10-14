#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M, L, R;
ll ans = 0;

vector<vector<pair<ll, ll> > > G;
vector<ll > prever;
//ダイクストラです（ワーシャルフロイドでやれ）
vector<ll > dijkstra(ll start, ll end){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, 1<<28);
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
        
        //2点間の最短距離を求めたいので見つけ次第処理を中断
        if(t_v == end){
            break;
        }

        //次探査する頂点はt_vなのでt_vから更に次にの頂点の繋がりをキューにいれる
        for(ll i = 0; i < G[t_v].size(); i++){
            //もし探査済みの頂点で，そこまでの累積距離より今更新しようとしている距離が
            //大きいときは更新しない
            ll to = G[t_v][i].first;
            ll cost = d+G[t_v][i].second;
            if(dist[to] <= cost) continue;
            //累積距離と次の頂点
            que.push(make_pair(cost, to));
            //仮dist
            dist[to] = cost;
        }
        //cout << endl;
    }   
    
    return dist;
 
}
 
int main() {
    //頂点数
    cin >> N >> M >> R;
    
    vector<ll > city;
    for(ll i = 0; i < R; i++){
        ll in = 0; cin >> in;
        city.push_back(in-1);
        //conf[in-1]++;
        //que.push(in-1);
    }

    G.assign(N, vector<pair<ll, ll > >());
 
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));    
    }

    //2点間の距離を全て出す...() R分だけ
    //指定された都市から回るのが一番効率的
    vector<vector<ll > > all_dist(R, vector<ll >(R, 1<<28));
    for(ll i = 0; i < R; i++){
        for(ll j = i; j < R; j++){
            vector<ll > dist = dijkstra(city[i], city[j]);
            //cout << city[i] << " " << city[j] << dist[city[j]] << endl;
            all_dist[i][j] = dist[city[j]];
            all_dist[j][i] = dist[city[j]];
        }
    }

    ll min_path = 1<<28;
    
    //順列の準備
    vector<ll > perm(R, 0);
    for(ll i = 0; i < R; i++) perm[i] = i;
    //答えを求める
    do{ 
        //最短を求める
        ll t_path = 0;
        for(ll i = 1; i < R; i++){
            //もしたどり着けない点があったら
            if(all_dist[perm[i-1]][perm[i]] == 1<<28) continue;
            t_path += all_dist[perm[i]][perm[i-1]];
        }
        min_path = min(t_path, min_path);
    }while(next_permutation(perm.begin(), perm.end()));

    cout << min_path << endl;

}