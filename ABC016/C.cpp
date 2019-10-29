#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll N, M; 

vector<vector<ll > > warshall(vector<vector<ll > > GRAPH){
    //中継点に関して
    for(ll reley = 0; reley < N; reley++){
        for(ll from = 0; from < N; from++){
            for(ll to = 0; to < N; to++){
                //中継した方がコストがかからないか否か
                //小さい順からコストが自明に決まっていく
                GRAPH[from][to] = min(GRAPH[from][to], GRAPH[from][reley] + GRAPH[reley][to]);
            }
        }
    }

    return GRAPH;
}

int main(){

    //頂点数と辺の数
    cin >> N >> M;

    vector<vector<ll > > G;
    G.assign(N, vector<ll >());

    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(i == j){
                //自分から自分へ
                G[i].push_back(0);
            }else{
                G[i].push_back(INF);
            }
        }       
    }
    //辺入力
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v;
        //適宜揃える
        w = 1;
        u--;
        v--;
        G[u][v] = min(G[u][v], w);
        G[v][u] = min(G[v][u], w);
    }

    G = warshall(G);

    for(ll i = 0; i < N; i++){
        ll ans = 0;
        for(ll j = 0; j < N; j++){
            if(i == j) continue;
            //cout << G[i][j] << endl;
            if(G[i][j] == 2){
                ans++;
            }
        }    
        cout << ans << endl;    
    }

}