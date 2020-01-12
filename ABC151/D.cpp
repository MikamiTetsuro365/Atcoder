#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

ll N, M;

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0,  0, 1,-1};

vector<vector<ll > > G;
 
vector<vector<ll > > bfs(ll x, ll y){
    //準備
    vector<vector<ll > > dist(N, vector<ll >(M, -1));
    queue<pi> que;
    //初期化
    dist[x][y] = 0;
    que.push(make_pair(x, y));
 
    while(!que.empty()){
        ll from_y = que.front().first;
        ll from_x = que.front().second;
        que.pop();
 
        for(ll i = 0; i < 4; i++){
            if(from_y + dy[i] >= 0 && from_y + dy[i] < N && from_x + dx[i] >= 0 && from_x + dx[i] < M){
                ll to_y = from_y + dy[i];
                ll to_x = from_x + dx[i];
                //壁がある時
                if(G[to_y][to_x] == -1 || dist[to_y][to_x] != -1) continue;
 
                dist[to_y][to_x] = dist[from_y][from_x] + 1;
                que.push(make_pair(to_y, to_x));

            }
        }
    }

    return dist;
}

int main() {

    cin >> N >> M;
    G.assign(N, vector<ll >());

    for(ll row = 0; row < N; row++){
        for(ll col = 0; col < M; col++){
            char t; cin >> t;
            if(t == '.'){
                G[row].push_back(0);
            }else{
                G[row].push_back(-1);
            }
        }
    }

    ll mx = -1;
    for(ll row = 0; row < N; row++){
        for(ll col = 0; col < M; col++){
            if(G[row][col] == -1) continue;
            //cout << row << " " << col << endl;
            vector<vector<ll > > dist = bfs(row, col);

            for(ll t_row = 0; t_row < N; t_row++){
                for(ll t_col = 0; t_col < M; t_col++){
                    mx = max(mx, dist[t_row][t_col]);
                    //cout<< dist[t_row][t_col] << endl;
                }    
            }
        }
    }

    cout << mx << endl;


}