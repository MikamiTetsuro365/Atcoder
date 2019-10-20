#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 114514191945;

vector<ll > dist;
vector<bool > seen;

void dfs(vector<vector<ll >> G, ll idx, ll from = -1){
    //
    if(seen[idx] == true) return;
    seen[idx] = true;
    for(ll i = 0; i < G[idx].size(); i++){
        //次の行き先は？
        ll to = G[idx][i];
        dfs(G, to, idx);
    }
}

//ベルマンフォード
bool bellman(vector<vector<pi > > G, ll start, ll N){
    //初期化
    dist[start] = 0;
    
    for(ll i = 0; i < N; i++){
        for(ll from = 0; from < N; from++){
            for(ll j = 0; j < G[from].size(); j++){
                ll to = G[from][j].first;
                ll cost = G[from][j].second;
                if(dist[from] != INF && dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                    if(i == N - 1){
                        //負の経路が会って頂点の数以上にループが回ってしまう
                        return false;
                    }
                }
            }       
        }
    }

   return true;

}

int main() {
    //探査開始点
    ll N, M, P; 
    cin >> N >> M >> P;

    vector<vector<ll > > front(N);
    vector<vector<ll > > back(N);
    vector<vector<pi> > tmpG(N);
    dist.assign(N, INF);

    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        //
        ll t_w = P - w;
        front[u].push_back(v);
        back[v].push_back(u);
        //今回は有向グラフ
        tmpG[u].push_back(make_pair(v, t_w));
    }

    //ゴール地点から辿ってスタート地点までに経由する頂点を列挙
    vector<bool > tmpSeen;
    seen.assign(N, false);
    dfs(front, 0);

    tmpSeen = seen;

    seen.assign(N, false);
    dfs(back, N - 1);

    //グラフを再構築する
    for(ll i = 0; i < N; i++){
        cout << tmpSeen[i] << endl;
        seen[i] = seen[i] & tmpSeen[i]; 
    }

    vector<vector<pi> > newG(N);
    for(ll i = 0; i < N; i++){   
        if(seen[i] == false) continue;
        for(ll j = 0; j < tmpG[i].size(); j++){
            if(seen[tmpG[i][j].first] == false) continue;
            newG[i].push_back(tmpG[i][j]);
        }
    }

    //cout << newG.size() << endl;
    
    if(bellman(newG, 0, newG.size()) == false){
        cout << "-1" << endl;
    }else{
        cout << max(-1 * dist[newG.size()-1], ll(0)) << endl;
    }

    /*
    for(ll i = 0; i < N; i++){
        cout << dist[i] << endl;
    }
    */

}