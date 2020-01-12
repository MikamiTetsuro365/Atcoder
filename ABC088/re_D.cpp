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
 
vector<vector<ll > > bfs(){
    //準備
    vector<vector<ll > > dist(N, vector<ll >(M, -1));
    queue<pi> que;
    //初期化
    dist[0][0] = 0;
    que.push(make_pair(0, 0));
 
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

    ll cn = 0;
    for(ll row = 0; row < N; row++){
        for(ll col = 0; col < M; col++){
            char t; cin >> t;
            if(t == '.'){
                G[row].push_back(0);
            }else{
                G[row].push_back(-1);
                cn++;
            }
        }
    }

    vector<vector<ll > > dist = bfs();

    if(dist[N-1][M-1] == -1){
        cout << -1 << endl;
        return 0;
    }

    ll ans = N * M - (dist[N-1][M-1] + 1) - cn;

    cout << ans << endl;


}