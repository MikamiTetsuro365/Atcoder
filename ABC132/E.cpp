#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;
typedef pair<pair<double, double >, double > pdd;
typedef pair<double, double > pd;  
vector<ll > vec;
vector<vector<ll > > vec2;
vector<bool > seen;
vector<vector<ll > > G;
vector<map<ll, ll> > conf;
queue<ll > check;
ll N, M, S, T;
ll MOD = 1000000007;
ll INF = 1145141919454519;
 
void dfs(ll root, ll idx, ll from = -1, ll depth = 0){
    //けんけんぱしたら終わり
    if(depth == 3){
        if(!conf[root][idx] == 1){
            //cout << root << " " << idx << endl;
            check.push(idx);
            conf[root][idx] = 1;
        }
        //seen[idx] = true;
        return;
    }
 
    //if(root != idx) seen[idx] = true;
 
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i];
        //cout << "to" << to << endl;
        //探査済み
        // if(seen[to] == true){
        //     continue;
        // }
 
        dfs(root, to , idx, depth + 1);
    }
    return;
}
 
vector<ll > bfs(ll start){
    //距離を初期化
    vector<ll > dist(conf.size(), -1);
    queue<ll > que;
 
    //始点start 初期化
    dist[start] = 0;
    que.push(start);
 
    while(!que.empty()){
        ll from = que.front();
        que.pop();
 
        auto begin = conf[from].begin(), end = conf[from].end();
        for (auto iter = begin; iter != end; iter++) {
            ll to = iter->first;
            //自己ループは念の為に排除
            if(from == to) continue;
            //すでに探査済み
            if(dist[to] != -1) continue;
 
            dist[to] = dist[from] + 1;
            que.push(to);
        }
    }
 
    return dist;
 
}
 
int main(){
    
    cin >> N >> M;
    //初期化
    G.assign(N, vector<ll >());
    conf.assign(N, map<ll, ll >());
    seen.assign(N, false);
 
    //グラフ入力
    for(ll i = 0; i < M; i++){
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        //有向グラフです
        G[u].push_back(v);
    }
 
    cin >> S >> T;
    S--;
    T--;
 
    check.push(S);
    
    while(!check.empty()){
        //cout << check.front() << endl;
        ll num = check.front();
        check.pop();
        if(conf[num].size() > 0) continue;
        seen.assign(N, false);
        dfs(num, num);
    }
 
    //確認
    // for(ll i = 0; i < N; i++){
    //     auto begin = conf[i].begin(), end = conf[i].end();
    //     for (auto iter = begin; iter != end; iter++) {
    //         cout << i << " " << iter -> first << endl;
    //     }        
    // }
 
    //最短経路を調べる
    vector<ll > dist = bfs(S);
 
    cout << dist[T] << endl;
 
}
