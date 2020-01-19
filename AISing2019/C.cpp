#include "bits/stdc++.h"
 
using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
typedef pair<pair<ll, ll >, char > piic;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;
 
ll N, M;
 
ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0,  0, 1,-1};
 
vector<string > G;

//黒で始まって白で終わる組を探す
//なお黒->白->黒みたいに交互にマス目をまたがないと駄目
//黒1->白1->黒2->の途中で通った黒2は黒1と同じような場所に行けるっぽい
//ので答えが同じになる

ll ans = 0;

void bfs(ll y, ll x){
    //準備
    vector<vector<ll > > dist(N, vector<ll >(M, -1));
    queue<pii> que;
    //初期化
    dist[y][x] = 0;
    que.push(make_pair(make_pair(y, x), '#'));
    //途中に発見した黒座標の管理
    vector<pi > B;
    B.push_back(make_pair(y, x));

    ll cn = 0;
    ll b_num = 1;

    while(!que.empty()){
        ll from_y = que.front().first.first;
        ll from_x = que.front().first.second;
        ll color = que.front().second;

        que.pop();
 
        for(ll i = 0; i < 4; i++){
            if(from_y + dy[i] >= 0 && from_y + dy[i] < N && from_x + dx[i] >= 0 && from_x + dx[i] < M){
                ll to_y = from_y + dy[i];
                ll to_x = from_x + dx[i];
                //もう訪れている時
                if(dist[to_y][to_x] != -1) continue;
                //黒->黒 白->白のとき
                if(color == G[to_y][to_x]) continue;

                dist[to_y][to_x] = dist[from_y][from_x] + 1;
                if(G[to_y][to_x] == '.'){
                    cn++;
                }
                que.push(make_pair(make_pair(to_y, to_x), G[to_y][to_x]));
                if(G[to_y][to_x] == '#'){
                    //cout << to_y << " " << to_x << endl;
                    G[to_y][to_x] = '*';
                    b_num++;
                }
                
            }
        }
    }
    ans += cn * b_num;
    cout << b_num << endl;
}
 
int main() {
 
    cin >> N >> M;
 
    for(ll row = 0; row < N; row++){
        string s;
        cin >> s;
        G.push_back(s);
    }
 
    ll mx = 0;
    for(ll row = 0; row < N; row++){
        for(ll col = 0; col < M; col++){
            if(G[row][col] == '#'){
                mx++;
                cout << row << " " << col << endl;
                bfs(row, col);
            }

        }
    }
 
    cout << ans << endl;
 
}