#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 114514191945;
ll N, M; 
vector<vector<pi > > G;
vector<ll > dist;

//ベルマンフォード
bool bellman(ll start){
    //準備
    //vector<ll > dist(N, INF);
    //初期化
    dist[start] = 0;
    
    for(ll i = 0; i < N; i++){
        for(ll from = 0; from < N; from++){
            for(ll j = 0; j < G[from].size(); j++){
                ll to = G[from][j].first;
                ll cost = G[from][j].second;
                if(dist[from] != INF && dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                    if(i == N-1){
                        //負の経路が会って頂点の数以上にループが回ってしまう
                        return false;
                    }
                }
            }       
        }
    }

    //確認
    /*
    for(ll i = 0; i < N; i++){
        if(dist[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }
    */

   return true;

}

int main() {
    //探査開始点
    ll S;
    cin >> N >> M >> S;

    G.assign(N, vector<pi >());
    dist.assign(N, INF);

    for(ll i = 0; i < M; i++){   
        ll u, v, w;
        cin >> u >> v >> w;
        //u--;
        //v--;
        //双方向に貼りましょうね
        G[u].push_back(make_pair(v, w));
        //G[v].push_back(make_pair(u, w)); 
    }
    
    if(bellman(S) == false){
        cout << "NEGATIVE CYCLE" << endl;
    }
}