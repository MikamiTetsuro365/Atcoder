#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

ll N, M;
vector<vector<ll > > G;
vector<ll > cost;
priority_queue<ll > c_que;
ll ans = 0;

vector<ll > bfs(ll start){
    start;
    //距離を初期化
    vector<ll > dist(G.size(), -1);
    queue<ll > que;

    //始点start 初期化
    dist[start] = 0;
    cost[start] = c_que.top();
    c_que.pop();
    que.push(start);


    while(!que.empty()){
        ll from = que.front();
        que.pop();

        for(ll i = 0; i < G[from].size(); i++){
            ll to = G[from][i];
            //すでに探査済み
            if(dist[to] != -1) continue;

            dist[to] = dist[from] + 1;
            cost[to] = c_que.top();
            ans += min(cost[from], cost[to]);
            que.push(to);
            c_que.pop();
        }
    }

    return dist;

}
int main(){


    cin >> N;

    G.assign(N, vector<ll >());
    cost.assign(N, -1);

    for(ll i = 0; i < N - 1; i++){
        //入力
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        //双方向に貼りましょうね
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(ll i = 0; i < N; i++){
        ll t; cin >> t;
        c_que.push(t);
    }
    //cout << "a" << endl;
    vector<ll > dist = bfs(0);

    cout << ans << endl;
    for(ll i = 0; i < N; i++){
        cout << (i ? " " : "") << cost[i];
    }
    cout << endl;
}