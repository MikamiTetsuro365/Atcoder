#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919;
//ll s_x, s_y;
ll ans = 0;
ll N, M, L;
vector<vector<ll > > G;
 
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0,  0, 1,-1};
 
ll bfs(ll s_y, ll s_x){
    //準備
    ll sum = 0;
    //探査済みかどうか判定用
    vector<vector<ll > > dist(N, vector<ll >(M, -1));
    queue<pi> que;
    //初期化
    //dist[s_y][s_x] = 0;
    que.push(make_pair(s_y, s_x));
 
    while(!que.empty()){
        ll from_y = que.front().first;
        ll from_x = que.front().second;
        que.pop();
        for(ll i = 0; i < 4; i++){
            //cout << from_y + dy[i] << " " << from_x + dx[i] << endl;
            if(from_y + dy[i] >= 0 && from_y + dy[i] < N && from_x + dx[i] >= 0 && from_x + dx[i] < M){
                ll to_y = from_y + dy[i];
                ll to_x = from_x + dx[i];

                //壁がある時
                if(G[to_y][to_x] == -1 || dist[to_y][to_x] != -1) continue;
                
                //探査済みにする
                dist[to_y][to_x] = dist[from_y][from_x] + 1;
                //探査対象としてキューに放り込む
                que.push(make_pair(to_y, to_x));
                //面積加算
                sum++;
            }
        }
    }

    return sum;
}
 
 
int main(){
    
    N = 10;
    M = 10;

    G.assign(N, vector<ll >());
 
    //初期化
    ll sum = 0;
    for(ll i = 0; i < N; i++){
        string s; cin >> s;
        for(ll j = 0; j < s.length(); j++){
            ll in;
            if(s[j] == 'x'){
                in = -1;
            }else{
                in = 1;
                sum++;
            }
            G[i].push_back(in);
        }       
    }

    //cout << sum << endl;
 
    for(ll i = 0; i < 10; i++){
        for(ll j = 0; j < 10; j++){
            //今いる場所を橋にした時，全ての陸地を辿れるか？
            //cout << G[i][j] << " ";
            ll tmp = G[i][j];
            G[i][j] = 1;
            //cout << bfs(i, j) << endl;
            //橋の文だけ陸地面積を1引く
            if(bfs(i, j) - 1 == sum){
                cout << "YES" << endl;
                return 0;
            }

            if(tmp == -1) G[i][j] = -1;
        }
    }
 
    cout << "NO" << endl;
 
}