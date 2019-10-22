#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = -1145141919;
ll N, M; 

vector<vector<ll > > G;
vector<vector<ll > > in;

ll dx[4] = {1, -1, 0 , 0};
ll dy[4] = {0,  0, 1 ,-1};

ll mx = 0;

void dfs(vector<vector<ll > > G, ll s_x, ll s_y, ll dis = 0){

    G[s_y][s_x] = 0;
    for(ll i = 0; i < 4; i++){
        ll n_x = s_x+dx[i];
        ll n_y = s_y+dy[i];
        if(!(n_y >= 0 && n_y < N && n_x >= 0 && n_x < M)) continue;
        if(G[n_y][n_x] == 0) continue;
        dfs(G, n_x, n_y, dis + 1);
    }

    mx = max(mx, dis);
}

int main(){

    //頂点数と辺の数
    cin >> N >> M;

    in.assign(N, vector<ll >());
    vector<bool > seen(N, false);
    
    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            ll t; cin >> t;
            in[i].push_back(t);
        }       
    }

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            if(in[i][j] == 0) continue;
            dfs(in, i, j);
        }       
    }

    cout << mx << endl;

}