#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
ll ans = 0;
ll N, M;
vector<vector<ll > > G;
 
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0,  0, 1,-1};

//BFSで池のところがあれば塗りつぶすを繰り返す
void bfs(ll s_y, ll s_x){
    //準備
    queue<pi> que;
    //初期化
    que.push(make_pair(s_y, s_x));
    //一度通ったところは検索対象にしない
    G[s_y][s_x] = -1;
    while(!que.empty()){
        ll from_y = que.front().first;
        ll from_x = que.front().second;
        //二度と検索しないようにする
        
        que.pop();

        for(ll i = 0; i < 4; i++){
            if(from_y + dy[i] >= 0 && from_y + dy[i] < N && from_x + dx[i] >= 0 && from_x + dx[i] < M){
                ll to_y = from_y + dy[i];
                ll to_x = from_x + dx[i];
                //池ではない時
                if(G[to_y][to_x] == -1) continue;
                que.push(make_pair(to_y, to_x));
                //一度通ったところは検索対象にしない
                G[to_y][to_x] = -1;
            }
        }
    }
    
    ans++;
}
 
 
int main(){
 
    cin >> N >> M;
    G.assign(N, vector<ll >());
    
    //初期化
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            ll t; cin >> t;
            if(t == 0){
                G[i].push_back(-1);
            }else{
                G[i].push_back(INF);
            }
            
        }       
    }
    
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < M; j++){
            if(G[i][j] == -1) continue;

            bfs(i, j);
        }       
    }
     
    cout << ans << endl;
 
}
