#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M, L;
ll ans = 0;

vector<vector<pair<ll, ll> > > G;
vector<ll > prever;
 
vector<ll > dijkstra(ll start){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, INFINITY);
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
 
int main() {
    //頂点数
    cin >> N >> M;

    G.assign(N, vector<pair<ll, ll > >());
 
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //双方向に貼りましょうね
        //make_pair(重み,貼りたい辺の先の頂点)
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));    
    }

    //ツーリストチケットを使用する前
    vector<ll > dis = dijkstra(0);
    //使用後
    vector<ll > after_dis(N, INFINITY);
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < G[i].size(); j++){
            ll tmp_v = G[i][j].first;
            ll tmp_vw = G[i][j].second;
            ll tmp_u = 0;
            ll tmp_uw = 0;
            //cout << "weight " << G[i][j].second << endl;
            //G[i][j].first  = -1;
            G[i][j].second = 0;
            //双方向につながっているのでもう語っぽも削除
            ll k = 0;
            for(k = 0; k < G[tmp_v].size(); k++){
                if(G[tmp_v][k].first == i){
                    tmp_u  = G[tmp_v][k].first;
                    tmp_uw = G[tmp_v][k].second;
                    
                    //G[tmp_v][k].first = -1;
                    G[tmp_v][k].second = 0;
                    break;
                }
            }
            vector<ll > t_dis = dijkstra(0);
            
            //確認
            /* 
            vector<ll > path = get_path(4);
            ll mx_path = 0;
            for(ll k = 0; k < path.size(); k++){
                cout << path[k] + 1 << " ";
            }
            cout << endl;
            */
            
            //もとに戻す
            G[i][j].second = tmp_vw;
            G[tmp_v][k].second = tmp_uw;
        }
    }

    /*
    ll ans = INFINITY;
    for(ll i = 0; i < N;i++){
        
        if(dis[i] == 0){
            cout << "0" << endl;
            continue;
        }

        ll t_ans = dis[i];
        cout << "dis " <<  dis[i] << endl;
        vector<ll > path = get_path(i);
        ll mx_path = 0;
        for(ll j = 0; j < path.size(); j++){
            mx_path = max(dis[path[j]], mx_path);
            t_ans += dis[path[j]];
        }
        t_ans -= mx_path;

        cout << t_ans << endl;
    

    }
    */
 
}