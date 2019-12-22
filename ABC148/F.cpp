#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
ll N, M, L;
ll ans = 0;

ll prohibitedArea;
pair<ll, ll > mx;
vector<bool > seen;
//vector<vector<pair<ll, ll> > > G;
//vector<ll > prever;
//最短距離を求めて高橋くんが進出してしまうと勝負が終わってしまう頂点を探す．負けるには最低何手必要か？
//勝負が終わってしまう頂点から青木くん側には絶対に進むことはできない．
//なぜなら青木くん側に進んでしまうと勝負が終わってしまうタイミングが早まる→交互に移動しているはずなのに矛盾が生じるから
//そこで，別の方向に最大限二人で動ける頂点を求める．
//その頂点こそが最適に動いた時に高橋くんが追い詰められる頂点となる．つまりその頂点から後一歩でも動くと青木くんと遭遇して負ける．動かざるを得ない.
//高橋くんが先手で青木くんが後手で青木くんの移動距離(手数)を求めたいので, マイナス1する．
class dijkstra{
    public:
    ll N;
    vector<vector<pair<ll, ll> > > G;
    vector<ll > dist;
    vector<bool > used;
    vector<ll > prever;
    priority_queue<pair<ll, ll > , vector<pair<ll, ll > >, greater<pair<ll, ll > > > que;
    

    //グラフに頂点を追加と初期化諸々
    dijkstra(ll n = 4545){
        N = n;
        G.assign(N, vector<pair<ll, ll > >());
        dist.assign(N, 11451419191919);
        used.assign(N, false);
        prever.assign(N, -1);
    }
    //グラフに辺を追加
    void addEdge(ll v, ll u, ll w = 1){
        G[u].push_back(make_pair(v, w));
    }

    //最短距離計算(始点=s)
    vector<ll > CalcDist(ll s){
        que.push(make_pair(0, s));
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
        }   
        return dist;
    }

    //経路列挙(終点=t)
    vector<ll > get_path(ll t){
        vector<ll > path;
        //始点を追加
        for(; t != -1; t = prever[t]){
            //cout << prever[t] << endl;
            path.push_back(t);
        }
        //reverse(path.begin(), path.end());
        return path;
    }

};

//ここは仮
vector<vector<pair<ll, ll> > > dfsG;
void dfs(ll idx, ll from = -1, ll pathSize = 0){

    seen[idx] = true;

    if(idx == prohibitedArea){
        return;
    }

    if(mx.first < pathSize){
        mx.first = pathSize;
        mx.second = idx;
    }

    for(ll i = 0; i < dfsG[idx].size(); i++){
        //次の行き先は？
        ll to = dfsG[idx][i].first;
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

    //ダイクストラ構築
    dijkstra D1(N);
    dijkstra D2(N);
    //dfsグラフ構築
    dfsG.assign(N, vector<pair<ll, ll > >());
    for(ll i = 0; i < N-1; i++){   
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        D1.addEdge(u, v);
        D1.addEdge(v, u);
        //D2.addEdge(u, v);
        //D2.addEdge(v, u);

        dfsG[u].push_back(make_pair(v, 1));
        dfsG[v].push_back(make_pair(u, 1));
    }

    D1.CalcDist(M-1);
    vector<ll > path = D1.get_path(L-1);
    ll tmp = D1.dist[L-1] / 2 + D1.dist[L-1] % 2;
    //ll next_start = 0;
    //cout << path[tmp]  << " " << M - 1 << endl;
    /*
    for(ll i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    */

    ll ans = tmp;

    ll next_start = path[tmp];
    prohibitedArea = path[tmp - 1];

    //cout << next_start << " " << prohibitedArea << endl;

    seen.assign(N, false);
    dfs(next_start);
    //D2.CalcDist(L-1);
    //ans += D2.dist[mx.second];

    ans += mx.first - 1;
    cout << ans << endl;

}