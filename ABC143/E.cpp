#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 11451419194545;
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
    ll L;
    cin >> N >> M >> L;

    vector<vector<ll > > G;
    //L以下の頂点に辺を貼ったグラフ
    vector<vector<ll > > G2;
    G.assign(N, vector<ll >());
    G2.assign(N, vector<ll >());
    
    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            G[i].push_back(INF);
            G2[i].push_back(INF);
        }       
    }
    //cout << G.size() << " " << G[0].size() << endl;
    //辺入力
    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        //適宜揃える
        u--;
        v--;
        //有向か無向かでコメントアウト　多重辺も防止
        G[u][v] = min(G[u][v], w);
        G[v][u] = min(G[v][u], w);
    }

    //ワーシャルフロイド実行
    G = warshall(G);

    //もう一度グラフを作る
    //L以下の燃料でたどり着ける町同士をつなぐ(燃料を補給せずに行ける町まで)
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(G[i][j] <= L ){
                G2[i][j] = 1;
            }
        }
    }

    //ワーシャルフロイド実行
    G2 = warshall(G2);

    ll Q; cin >> Q;

    //確認
    vector<ll > ans;
    for(ll i = 0; i < Q; i++){
        ll s, t; cin >> s >> t;
        s--; t--;
        if(G2[s][t] == INF){
            cout << -1 << endl;
        }else{
            //最初の町へは補給無しで行けるので
            cout << G2[s][t] - 1 << endl;
        }
    }

}