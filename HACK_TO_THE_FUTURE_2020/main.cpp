#define _USE_MATH_DEFINES
#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<ll, pair<ll, ll > > iip;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll gy, gx;
ll N, M, B; 

ll dx[4] = { 1, 0, -1, 0 };
ll dy[4] = { 0, 1, 0, -1 };

vector<pi > bfs(vector<vector<ll > > G, ll s_y, ll s_x){
    //準備
    vector<vector<ll > > dist(N, vector<ll >(N, -1));
    queue<pi> que;
    //経路復元用
    vector<vector<ll > > prev_x(N, vector<ll >(N, -1));
    vector<vector<ll > > prev_y(N, vector<ll >(N, -1));
    //初期化
    dist[s_y][s_x] = 0;
    que.push(make_pair(s_y, s_x));
 
    while(!que.empty()){
        ll from_y = que.front().first;
        ll from_x = que.front().second;
        que.pop();
        //cout << "a" << endl;
        for(ll i = 0; i < 4; i++){
            
            ll to_y = (N + from_y + dy[i]) % N;
            ll to_x = (N + from_x + dx[i]) % N;
            //ll to_y = from_y + dy[i];
            //ll to_x = from_x + dx[i];
            //if(to_x < 0 || to_x >= N || to_y < 0 || to_y >= N) continue;


            //ブロックが置かれている時と探査済みの時
            if(G[to_y][to_x] == -1) continue;

            if(dist[to_y][to_x] == -1){
                dist[to_y][to_x] = dist[from_y][from_x] + 1;
                que.push(make_pair(to_y, to_x));
                //どの頂点から今注目している頂点に行くか
                prev_x[to_y][to_x] = from_x;
                prev_y[to_y][to_x] = from_y;
            }

        }
    }
    //cout << "conf"  << prev_x[17][33] << " " << prev_y[17][33] << endl;
    vector<pi > path;
    ll x = gx, y = gy;
    ll cn = 0;
    while(x != -1 && y != -1){
        //cout << x << " " << y << " Next" << prev_x[y][x] << " " << prev_y[y][x] << endl;
        path.push_back(make_pair(y, x));
        ll px = prev_x[y][x];
        ll py = prev_y[y][x];
        x = px;
        y = py;
    }
    //cout << cn << endl;

    return path;
}
 


int main(){

    cin >> N >> M >> B;
    vector<vector<ll > > G(N, vector<ll >(N, 0));
    vector<vector<char > > kanban(N, vector<char >(N, 'H'));
    
    cin >> gy >> gx;


    vector<pair<pair<ll, ll >, char > > robot;
    vector<pair<pair<ll, ll >, char > > ans;

    //priority_queue<ll, vector<ll >, greater<ll > > que;
    
    ll A = 0;
    ll K = 0;
    for(ll i = 0; i < M; i++){
        ll ry, rx; char c; cin >> ry >> rx >> c;
        if(ry == gy && rx == gx) continue;
        robot.push_back(make_pair(make_pair(ry,rx),c));
    }

    for(ll i = 0; i < B; i++){
        ll by, bx; cin >> by >> bx;
        G[by][bx] = -1;
    }


    for(ll i = 0; i < M; i++){
        //cout << robot[i].first.first << " " << robot[i].first.second << endl;
        vector<pi > path = bfs(G, robot[i].first.first, robot[i].first.second);
        //パスを辿ってみる
        ll py = gy; ll px = gx;
        
        for(ll j = 1; j < path.size(); j++){
            ll ny = path[j].first;
            ll nx = path[j].second;
            
            //if(kanban[ny][nx] != 'H') continue;
            
            if(px == nx){
                if(py == N-1 && ny == 0){
                    kanban[ny][nx] = 'D';
                }else if(py == 0 && ny == N-1){
                    kanban[ny][nx] = 'U';
                }else{

                }
                if(py < ny){
                    if(py == 0 && ny == N-1){
                        kanban[ny][nx] = 'D';
                    }else{
                        kanban[ny][nx] = 'U';
                    }
                }else{
                    if(py == N-1 && ny == 0){
                        kanban[ny][nx] = 'U';
                    }else{
                        kanban[ny][nx] = 'D';
                    }
                }
            }

            if(py == ny){

                if(px < nx){
                    if(px == 0 && nx == N-1){
                        kanban[ny][nx] = 'R';
                    }else{  
                        kanban[ny][nx] = 'L';
                    }
                    
                }else{
                    if(px == N-1 && nx == 0){
                        kanban[ny][nx] = 'L';
                    }else{
                        kanban[ny][nx] = 'R';
                    }
                }

            }

            px = nx;
            py = ny;

        }
        //cout << "OK" << endl;
    }

    //出力設定
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(kanban[i][j] != 'H') K++;
            
        }       
    }
    cout << K << endl;

    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            if(kanban[i][j] != 'H') cout << i << " " << j << " " << kanban[i][j] << endl;
        }       
    }

}