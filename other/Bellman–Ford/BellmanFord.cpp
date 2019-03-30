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
ll r;
ll INF = 1<<28;
//ベルマンフォード
bool bellman(vector<vector<pair<ll, ll> > > G, ll start){
    //準備
    vector<ll > dist(N, 1<<28);

    //初期化
    dist[start] = 0;
    
    for(ll i = 0; i < N; i++){
        for(ll from = 0; from < N; from++){
            for(ll j = 0; j < G[from].size(); j++){
                ll cost = G[from][j].first;
                ll to = G[from][j].second;
                if(dist[from] != INF && dist[to] > dist[from] + cost){
                    dist[to] = dist[from] + cost;
                }
                if(i == N-1){
                    //負の経路が会って頂点の数以上にループが回ってしまう
                    return false;
                }
            }       
        }
    }

    //確認
    for(ll i = 0; i < N; i++){
        if(dist[i] == INF){
            cout << "INF" << endl;
        }else{
            cout << dist[i] << endl;
        }
    }


   return true;

}

int main() {
    //頂点数
    cin >> N >> M >> r;
    vector<vector<pair<ll, ll> > > G(N);

    ll a, b, t;
    for(ll i = 0; i < M; i++){   
        cin >> a >> b >> t;
        //入力の仕方によってはマイナスしとく
        //a--;
        //b--;
        //無効グラフなので
        G[a].push_back(make_pair(t,b));
    }

    bool minus = bellman(G, r);
    
    if(minus == false){
        cout << "loop" << endl;
    }
    
}