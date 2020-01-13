#include "bits/stdc++.h"

using namespace std;
typedef long long int ll;
typedef pair<ll, ll > pi;  
typedef pair<pair<ll, ll >, ll > pii;  
vector<ll > vec;
vector<vector<ll > > vec2;
ll MOD = 1000000007;
ll INF = 1145141919454519;

using namespace std;

ll G[4][3];

ll dx[4] = {1, -1, 0, 0};
ll dy[4] = {0,  0, 1,-1};

ll Key[10][2] = {{0, 2},{1, 2},{1, 1},{1, 0},{2, 2},{2, 1},{2, 0},{3, 2},{3, 1},{3, 0}}; 

vector<vector<ll > > bfs(ll y, ll x){
    //準備
    vector<vector<ll > > dist(4, vector<ll >(3, -1));
    queue<pi> que;
    //初期化
    dist[y][x] = 0;
    que.push(make_pair(y, x));
 
    while(!que.empty()){
        ll from_y = que.front().first;
        ll from_x = que.front().second;
        que.pop();
 
        for(ll i = 0; i < 4; i++){
            if(from_y + dy[i] >= 0 && from_y + dy[i] < 4 && from_x + dx[i] >= 0 && from_x + dx[i] < 3){
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

int main(){

    ll M;
    ll r; 
    cin >> M >> r;

    //初期化
    G[0][0] = -1;
    G[0][1] = -1;
    ll ans = INF;
    //すべてのテンキーからテンキーへの距離
    vector<vector<vector<ll > > > dist;
    for(ll i = 0; i < 10; i++){
        dist.push_back(bfs(Key[i][0], Key[i][1]));
    }

    //dp[i][j][k] 
    //i桁目で余りjになるときに入力したテンキーkのうち最小回数
    vector<vector<vector<ll>>> dp(20, vector<vector<ll>>(100019, vector<ll>(10, INF)));
    //初期値
    dp[0][0][0] = 0;

    for(ll i = 0; i < 16; i++){
        //cout << i << endl;
        for(ll mo = 0; mo < 100000; mo++){
            for(ll k = 0; k < 10; k++){
                if(dp[i][mo][k] == -1) continue;
                ll now_cost = dp[i][mo][k];
                //次のテンキーを押しにいく
                for(ll next_k = 0; next_k < 10; next_k++){
                    ll next_mo = (mo * 10 + next_k) % M;
                    ll move = dist[k][Key[next_k][0]][Key[next_k][1]];
                    //cout << mo << " " << k << " " <<  next_mo << " " << next_mo << endl;
                    //移動と押す回数でmove+1
                    dp[i+1][next_mo][next_k] = min(dp[i+1][next_mo][next_k], now_cost + move + 1);
                    if(next_mo == 13) cout << dp[i+1][next_mo][next_k] << endl;
                    //cout << dp[i+1][next_mo][next_k] << endl;
                }
            }
        }           
    }

    //答え確認
    for(ll k = 0; k < 10; k++){
        cout << dp[16][r][k] << endl;
        ans = min(ans, dp[16][r][k]);
    }

    // for(ll k = 0; k < 100000; k++){
    //     ll s = 0;
    //     ll t_ans = 0;
    //     ll t_r = r + M * k;
    //     string R = to_string(t_r);
    //     //cout << R << endl;
    //     for(ll i = 0; i < R.length(); i++){
    //         //逆転してるy xの順
    //         vector<vector<ll > > dist = bfs(Key[s][0], Key[s][1]);
    //         //cout << Key[s][0] << " " << Key[s][1] << endl;
    //         /*
    //         for(ll row = 0; row < 4; row++){
    //             for(ll col = 0; col < 3; col++){
    //                 cout << dist[row][col] << " ";
    //             }            
    //             cout << endl;
    //         }
    //         */
            
            
    //         //cout << R[i]-'0' << endl;
    //         //cout << "z:" << Key[R[i]-'0'][0] << " " << Key[R[i]-'0'][1] << endl;
    //         //cout << dist[Key[R[i]-'0'][0]][Key[R[i]-'0'][1]] << endl;
    //         s = R[i]-'0';
    //         //移動
    //         t_ans += dist[Key[R[i]-'0'][0]][Key[R[i]-'0'][1]];
    //         //押す
    //         t_ans++;
    //     }
    //     //cout << t_ans << endl;
    //     ans = min(ans, t_ans);
    // }
    

    cout << ans << endl;
}