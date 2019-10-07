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
    cin >> N >> M >> L;
    //トラックの数
    vector<ll > T(N, 0);
    ll count = 0;
    for(ll i = 0; i < N; i++){
        cin >> T[i];
        if(T[i] > 0) count++;
    }

    if(count == 1){
        cout << 0 << endl;
        return 0;
    }

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

    ll ans = INFINITY;
    //全探査
    for(ll i = 0; i < N; i++){
        ll t_ans = 0;
        vector<ll > dis = dijkstra(i);
        //レッカー車の初期位置以外に集めるとき
        //Lから集積場所まで集めておく
        bool f = false;
        ll tmp_posi = 0;
        //集積所とレッカー車が別の場所にあるとき
        if(i != L - 1){
            //集積所までの経路を出す
            vector<ll > path = get_path(L - 1);
            //集積所にレッカー車を向かわせる途中でトラックがおいてある場所が
            //あればトラックを拾ってから集積所に行く（効率的）
            for(ll j = 0; j < path.size();j++){
                if(T[path[j]] > 0){
                    //トラックを無事拾えたら拾った場所を記録
                    f = true;
                    tmp_posi = path[j];
                    //拾ったところでトラックの台数を減らす
                    T[path[j]]--;
                    break;
                }
            }
            //レッカー車の移動距離に拾ったところから集積所までの距離を足しておく
            t_ans += dis[L - 1];
        }
        //集積所から各交差点へトラックをひたすら回収したときの距離を計算
        for(ll j = 0; j < N; j++){
            //最初から集積所のトラックが集まっているので
            if(i == j) continue;
            t_ans += dis[j] * 2 * T[j]; 
        }
        //トラックを拾ったところにトラックを戻す
        if(f == true){
            T[tmp_posi]++;
        }
        ans = min(ans, t_ans);
    }

    cout << ans << endl;
    /*
    dijkstra(0);
    vector<ll > ans = get_path(4);
    for(ll i=0; i < ans.size();i++){
        cout << ans[i]+1 << endl;
    }
    */

    //dijkstra(2);
 
    //cout << ans << endl;
 
}