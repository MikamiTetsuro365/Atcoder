#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454545;
ll N, M, S, T;
 
vector<ll > dijkstra(vector<vector<pi > > G, ll start){
    //準備
    vector<bool > used(N, false);
    vector<ll > dist(N, INF);
    priority_queue<pi , vector<pi >, greater<pi > > que;
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
    cin >> N >> M >> S >> T;

    vector<vector<pi > > yen(N);
    vector<vector<pi > > snuuke(N);
 
    for(ll i = 0; i < M; i++){   
        ll u, v, a, b;
        cin >> u >> v >> a >> b;
        u--;
        v--;
        //双方向に貼りましょうね
        yen[u].push_back(make_pair(v, a));
        yen[v].push_back(make_pair(u, a));    

        snuuke[u].push_back(make_pair(v, b));
        snuuke[v].push_back(make_pair(u, b));   
    }

    //i年後には強制的にi番目を通らざるを得ない
    //そこまでの円とそこからのSnuukeでコストが決まる
    //更にi-1年後にはi-1番目を通れる可能性があり，そちらのほうがコストが安いかも
    //そのときに答えを更新していく
    //s-(経由地)-tで円-Snuukeがどれだけ消費されるかを求めれば良い

    //円でsからスタート
    vector<ll > distYen = dijkstra(yen, S-1);
    //snuukeでtからスタート
    vector<ll > distSnuuke = dijkstra(snuuke, T-1);
    //答え
    vector<ll > ans(N, 0);

    ll mn = INF;
    for(ll i = N-1; i >= 0; i--){
        ll tmp = distYen[i] + distSnuuke[i];
        if(tmp < mn){
            mn = tmp;
        }
        ans[i] = mn;
    }

    for(ll i = 0; i < N; i++){
        cout << (ll)(1e15 - ans[i]) << endl;
    }

}