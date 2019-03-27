#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
#include <cmath>
#include <iomanip>
#include <queue>
//greaterで必要
#include <functional>
//重複チェック
#include <set>


using namespace std;
typedef long long ll;
ll N;
ll M;
//vector<vector<pair<ll, ll> > > G;

ll ans = 1<<28;

void dijkstra(vector<vector<pair<ll, ll> > > G, ll start){
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
            if(dist[G[t_v][i].second] <= d+G[t_v][i].first) continue;
            //累積距離と次の頂点
            que.push(make_pair(d+G[t_v][i].first, G[t_v][i].second));
        }
    }   

    //確認
    ll mx = -1;
    for(ll i = 0; i < N; i++){
        //cout << i << " " << dist[i] << endl;
        mx = max(mx, dist[i]);
    }
    
    ans = min(ans, mx);
    //cout << mx << " " << ans << endl;

}

int main() {
    //頂点数
    cin >> N >> M;
    vector<vector<pair<ll, ll> > > G(N);

    ll a, b, t;
    for(ll i = 0; i < M; i++){   
        cin >> a >> b >> t;
        a--;
        b--;
        //無効グラフなので
        G[a].push_back(make_pair(t,b));
        G[b].push_back(make_pair(t,a));
    }

    /*
    for(ll i = 0; i < N; i++){   
        for(ll j = 0; j < G[i].size(); j++){
            cout << G[i][j].first << " " << G[i][j].second << endl;
        }
    }
    */

    for(ll i = 0; i < N; i++){
        dijkstra(G, i);
    }

    cout << ans << endl;
}