#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll s_x, s_y;
ll ans = 0;
ll N, M, L;
vector<vector<ll > > G;

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0,  0, 1,-1};

void bfs(ll goal){
    //準備
    vector<vector<ll > > dist(N, vector<ll >(M, -1));
    queue<pi> que;
    //初期化
    dist[s_y][s_x] = 0;
    que.push(make_pair(s_y, s_x));

    while(!que.empty()){
        ll from_y = que.front().first;
        ll from_x = que.front().second;
        que.pop();

        for(ll i = 0; i < 4; i++){
            if(from_y + dy[i] >= 0 && from_y + dy[i] < N && from_x + dx[i] >= 0 && from_x + dx[i] < M){
                ll to_y = from_y + dy[i];
                ll to_x = from_x + dx[i];
                //壁がある時と枝刈り
                if(G[to_y][to_x] == -1 || dist[to_y][to_x] != -1) continue;

                dist[to_y][to_x] = dist[from_y][from_x] + 1;
                que.push(make_pair(to_y, to_x));
                
                if(G[to_y][to_x] == goal){
                    ans += dist[to_y][to_x];
                    s_y = to_y;
                    s_x = to_x;
                    return;
                }
            }
        }
    }
}


int main(){

    cin >> N >> M >> L;
    G.assign(N, vector<ll >());

    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            char t; cin >> t;
            ll in;
            if(t == 'X'){
                in = -1;
            }else if(t == '.'){
                in = 0;
            }else if(t == 'S'){
                in = 0;
                s_x = j;
                s_y = i;
            }else{
                in = t - '0';
            }
            G[i].push_back(in);
        }       
    }
    

    for(ll i = 1; i <= 9; i++){
        //cout << i << endl;
        bfs(i);
        //cout << ans << endl;
    }

    cout << ans << endl;

}