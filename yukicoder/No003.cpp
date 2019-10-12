#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;

ll ans = INFINITY;
ll N;

vector<ll > bfs(vector<vector<ll > > G, ll start){
    start;
    //距離を初期化
    vector<ll > dist(G.size(), -1);
    queue<ll > que;

    //始点start 初期化
    dist[start] = 0;
    que.push(start);

    while(!que.empty()){
        ll from = que.front();
        que.pop();

        for(ll i = 0; i < G[from].size(); i++){
            ll to = G[from][i];
            //すでに探査済み
            if(dist[to] != -1) continue;

            dist[to] = dist[from] + 1;
            que.push(to);
        }
    }

    return dist;

}

int main(){


    cin >> N;

    vector<vector<ll > > G;
    G.assign(N + 1, vector<ll >());
    
    //0から開始マス1への移動
    G[0].push_back(1);

    for(ll i = 1; i <= N; i++){
        ll bit_count = __builtin_popcount(i);
        //cout << i-1 + bit_count << " " << i-1 - bit_count << endl;
        if(i + bit_count <= N){
            G[i].push_back(i + bit_count);
            //G[i-1 + bit_count].push_back(i-1);
            //cout << 0 << endl;
        } 
        if(i - bit_count > 0){
            G[i].push_back(i - bit_count);
           //G[i-1 - bit_count].push_back(i-1);
            
        }
    }

    vector<ll > dist = bfs(G, 0);

    cout << dist[N] << endl;

}